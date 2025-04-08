#include <iostream>
#include <exception>

void my_terminate(void)
{
	std::cout << "my_terminate called" << std::flush;
	std::abort();
}

int main()
{
	std::set_terminate(my_terminate);

	auto fg = get_terminate();

	fg();
}
