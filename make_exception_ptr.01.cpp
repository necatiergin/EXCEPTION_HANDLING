#include <iostream>   
#include <exception>  
#include <stdexcept>  

int main()
{
    //...
    auto p = std::make_exception_ptr(std::range_error("aralik disi deger"));

    //...
    try {
        std::rethrow_exception(p);
    }
    catch (const std::exception& e) {
        std::cout << "hata yakalandi: " << e.what() << '\n';
    }
}
