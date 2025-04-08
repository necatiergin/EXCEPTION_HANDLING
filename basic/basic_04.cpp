#include <iostream>
#include <exception>
#include <string>

void my_terminate(void)
{
	std::cout << "my_terminate called" << std::flush;
	std::abort();
}

int main()
{
	std::set_terminate(my_terminate);
	std::string str{ "necati ergin" };

	auto c = str.at(20);
}
