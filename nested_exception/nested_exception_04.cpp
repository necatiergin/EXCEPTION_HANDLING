#include <exception>
#include <iostream>
#include <stdexcept>

int main() 
{
    try {
        try {
            throw std::runtime_error{ "low-level error" };
        }
        catch (...) {
            std::throw_with_nested(std::logic_error{ "high-level error" });
        }
    }
    catch (const std::exception& e) {
        std::cout << "Top: " << e.what() << '\n';

        try {
            if (auto ne = dynamic_cast<const std::nested_exception*>(&e)) {
                ne->rethrow_nested();
            }
        }
        catch (const std::exception& ex) {
            std::cout << "nested exception : " << ex.what() << '\n';
        }
    }
}
