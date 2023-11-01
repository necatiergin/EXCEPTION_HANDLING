#include <iostream>

class NecEx {
//
	unsigned char buffer[1024]{};
};

void func()
{
	try {
		throw NecEx{};
	}
	catch (const NecEx &necex) {
		std::cout << "&necex = " << &necex << '\n';
		//throw;
		throw necex;
	}
}


void foo()
{
	try {
		func();
	}
	catch (const NecEx& necex) {
		std::cout << "&necex = " << &necex << '\n';
	}
}

int main()
{
	foo();
}
