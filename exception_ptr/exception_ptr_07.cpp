#include <exception>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <optional>

struct WorkResult {
    int value{};
    std::exception_ptr error; 
};

void worker(WorkResult& out, int x) 
{
    try {
        // ... work
        if (x < 0)
            throw std::runtime_error("disk read failed"); 
        out.value = 42;
    }
    catch (...) {
        out.error = std::current_exception(); 
    }
}

int main() 
{
    WorkResult result{};

    std::thread t(worker, std::ref(result), -1);
    std::thread t(worker, std::ref(result), 9);
    t.join();

    if (result.error) {
        try {
            std::rethrow_exception(result.error);
        }
        catch (const std::exception& e) {
            std::cout << "Worker failed: " << e.what() << '\n';
        }
    }
    else {
        std::cout << "Worker ok, value = " << result.value << '\n';
    }
}
