#include <stdexcept>
#include <iostream>

class NecEx {};

void func(void)
{
	//throw std::out_of_range{ "out of range error in func!\n" }; // [1]
	//throw std::logic_error{ "logic error in func!\n" }; // [2]
	//throw std::runtime_error{ "runtime error in func!\n" }; // [3]
	throw NecEx{}; // [4]
}

int main()
{
	try {
		func();
	}
	catch (const std::out_of_range& ex) {	    //1
		std::cout << "[1] " << ex.what() << '\n';
	}
	catch (const std::logic_error& ex) {		
		std::cout << "[2] " << ex.what() << '\n';
	}
	catch (const std::exception& ex) {
		std::cout << "[3] " << ex.what() << '\n';
	}
	catch (...) {
		std::cout << "[4] unknown exception" << '\n';
	}
}
