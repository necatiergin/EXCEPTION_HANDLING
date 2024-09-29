#include <iostream>
#include <variant>

int main()
{
    std::variant<int, float> var(34);
    
    try
    {
        std::get<double>(var);
    }
    
    catch (const std::bad_variant_access& e)
    //catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}
