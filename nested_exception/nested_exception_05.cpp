#include <exception>
#include <iostream>

int main() 
{
    //std::nested_exception ex;
    std::nested_exception ex;

    if (auto eptr = ex.nested_ptr()) {
        std::cout << "there is a stored exception\n";
    }
    else {
        std::cout << "there is no stored exception\n";
        ex.rethrow_nested(); //std::terminate called
    }
}
