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

        if (auto ne = dynamic_cast<const std::nested_exception*>(&e)) {
            // eptr is std::exception_ptr
            if (auto eptr = ne->nested_ptr()) {
                try {
                    std::rethrow_exception(eptr);
                }
                catch (const std::exception& inner) {
                    std::cout << "Nested: " << inner.what() << '\n';
                }
            }
        }
    }
}
