#include <iostream>

class NecException : public std::exception {
public:
    NecException(const char* msg) : pmsg(msg) {}
    const char* what() const noexcept override
    {
        return pmsg;
    }
private:
    const char* pmsg;
};

int main() 
{
    try {
        throw NecException("Nec Error!!!");
    }
    catch (const NecException& ex) {
        std::cout << "exception caught: " << ex.what() << '\n';
    }
}
