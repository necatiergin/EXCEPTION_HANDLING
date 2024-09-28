//std::terminate is called if a rethrow statement isevaluated when no exception is being handled.

#include <iostream>

void nec_terminate()
{
	std::cout << "nec_terminate()\n";
	std::abort();
}

void func()
{
	throw;
}

int main()
{
	std::set_terminate(nec_terminate);
	func();
}
