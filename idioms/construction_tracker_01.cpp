#include <iostream>
#include <stdexcept>
#include <cassert>

struct X {
    X(const char*)
    {
        throw std::runtime_error("X Error");
    }
};

struct Y {
    Y(const char*)
    {
        throw std::runtime_error("Y Error");
    }
};

struct Z {
    Z(const char*)
    {
        throw std::runtime_error("Z Error");
    }
};

class Nec {
    X mx;
    Y my;
    Z mz;
    enum TrackerType { NONE, ONE, TWO, THREE };
public:
    Nec(TrackerType tracker = NONE)
        try    // X constructor try block.
        : mx((tracker = ONE, "hello"))  // Can throw std::exception
        , my((tracker = TWO, "world"))   // Can throw std::exception
        , mz((tracker = THREE, "world")) // Can throw std::exception
    {
        assert(tracker == THREE);
        // ... constructor body ...
    }
    catch (std::exception const& e)
    {
        if (tracker == ONE) {
            std::cout << "X threw: " << e.what() << '\n';
        }
        else if (tracker == TWO) {
            std::cout << "Y threw: " << e.what() << '\n';
        }
        else if (tracker == THREE) {
            std::cout << "Z threw: " << e.what() << '\n';
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
        std::cout << "exception caught: " << e.what() << '\n';
    }

}
