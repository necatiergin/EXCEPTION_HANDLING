#include <iostream>
#include <exception>

struct NecEx {

	NecEx() = default;

	NecEx(const NecEx&)
	{
		std::cout << "NecEx copy ctor throws an exception\n";
		throw std::exception{};
	}
};

void foo()
{
	NecEx ex;
	throw ex;
}

void myterminate()
{
	std::cout << "my terminate called!\n";
}

int main()
{
	std::set_terminate(myterminate);

	try {
		foo();
	}
	catch (NecEx) { //catch param. is not a reference (copy ctor. called)

	}
}
