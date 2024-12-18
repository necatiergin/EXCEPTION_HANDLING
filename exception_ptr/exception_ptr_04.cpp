#include <iostream>   
#include <exception>  
#include <stdexcept>  

void foo(std::exception_ptr eptr)
{
    //...
    std::rethrow_exception(eptr);
}
int main()
{
    //...
    auto p = std::make_exception_ptr(std::range_error("value - out of range"));

    //...
    try {
        foo(p);
    }
    catch (const std::exception& e) {
        std::cout << "exception caught: " << e.what() << '\n';
    }
}
