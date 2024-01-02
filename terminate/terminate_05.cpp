#include <iostream>
#include <stdexcept>

void my_terminate()
{
	std::cout << "my terminate_called\n";
	std::abort();
}


void foo()
{
	std::cout << "foo() called!\n";
	throw std::runtime_error{ "error in foo" };
}

int main()
{
	set_terminate(&my_terminate);

	foo();
}
