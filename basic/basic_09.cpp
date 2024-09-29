#include <iostream>

struct NecEx {

	NecEx()
	{
		std::cout << "NecEx default ctor this = " << this << '\n';
	}

	NecEx(const NecEx&)
	{
		std::cout << "NecEx copy ctor this = " << this << '\n';
	}

	NecEx(NecEx&&)
	{
		std::cout << "NecEx move ctor this = " << this << '\n';
	}

	~NecEx()
	{
		std::cout << "NecEx destructor this = " << this << '\n';
	}
};


void foo()
{
	throw NecEx{};
}

int main()
{
	try {
		foo();
	}
	catch (const NecEx& ex) {
		std::cout << "exception caught... &ex =" << &ex << '\n';
	}
}
