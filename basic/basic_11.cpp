#include <iostream>
#include <string>

class NecException : public std::exception {
public:
    NecException(const char* str) : m_str(str) {}
    NecException(const std::string& str) : m_str(str) {}
    const char* what() const noexcept override
    {
        return m_str.c_str();
    }
private:
    const std::string m_str;
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
