#include <iostream>
#include <stdexcept>
#include <cassert>

struct X {
    X(const char *) 
    {
        throw std::runtime_error("X Error"); 
    }
};

struct Y {
    Y(const char *) 
    {
        throw std::runtime_error("Y Error");
    }
};

struct Z {
    Z(const char *)
    {
        throw std::runtime_error("Z Error");
    }
};

class Nec {
    X ma;
    Y mb;
    Z mc;
    enum TrackerType {NONE, ONE, TWO, THREE};
public:
    Nec(TrackerType tracker = NONE)
        try    // X constructor try block.
        : ma((tracker = ONE, "hello"))  // Can throw std::exception
        , mb((tracker = TWO, "world"))   // Can throw std::exception
        , mc((tracker = THREE, "world")) // Can throw std::exception
    {
        assert(tracker == THREE);
        // ... constructor body ...
    }
    catch (std::exception const& e)
    {
        if (tracker == ONE) {
            std::cout << "X threw: " << e.what() << std::endl;
        }
        else if (tracker == TWO) {
            std::cout << "Y threw: " << e.what() << std::endl;
        }
        else if (tracker == THREE) {
            std::cout << "Z threw: " << e.what() << std::endl;
        }

        throw;
    }
};

int main(void)
{
    try {
        Nec mynec;
    }
    catch (std::exception const& e) {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
    
}
