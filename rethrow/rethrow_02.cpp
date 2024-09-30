#include <exception>
#include <stdexcept>
#include <iostream>

void func()
{
	try {
		throw std::out_of_range{ "range hatasi" };
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught in func : " << ex.what() << "\n";
		//see the difference between two throw statement.
		throw ex;
		//throw; 
	}
}


int main()
{
	try {
		func();
	}
	catch (const std::out_of_range&) {
		std::cout << "exception caught:  (std::out_of_range)\n";
	}

	catch (const std::exception&) {
		std::cout << "exception caught: (std::exception)\n";
	}
}
