#include <iostream>       
#include <exception>      
#include <stdexcept>      

// recursively print exception what's string:

void print_exception(const std::exception& e) {
    std::cerr << e.what() << '\n';
    try {
        std::rethrow_if_nested(e);
    }
    catch (const std::exception& nested) {
        std::cerr << "nested: ";
        print_exception(nested);
    }
}

void bar()
{
    throw std::runtime_error("exception from bar");
}

// throws an exception nested in another:
void foo() 
{
    try {
        bar();
    }
    catch (const std::exception&) {
        std::throw_with_nested(std::runtime_error("exception from foo"));
    }
}

int main() 
{
    try {
        foo();
    }
    catch (std::exception& e) {
        print_exception(e);
    }
}
