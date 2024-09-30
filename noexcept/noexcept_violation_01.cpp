#include <exception>
#include <iostream>
#include <cstdlib>

void func()
{
	throw std::exception{};
}

void foo()noexcept
{
	func();
}

// as function foo is noexcept specified when it throws an exception the compiler will call std::terminate 
// the exception thrown in the following code would not be caught.

void my_terminate(void)
{
	std::cout << "my terminate called\n";
	std::abort();
}

int main()
{
	std::set_terminate(&my_terminate);

	try {
		foo();
	}
	catch (const std::exception& ex) {
		std::cout << "hata yakalandi : " << ex.what() << "\n";
	}
}
