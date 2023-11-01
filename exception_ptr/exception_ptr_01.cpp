#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

void handle_stored_exception(std::exception_ptr eptr) 
{
	try {
		if (eptr) {
			std::rethrow_exception(eptr);
		}
	}
	catch (const std::exception& ex) {
		std::cout << "caught exception is: " << ex.what() << '\n';
	}
}

int main()
{
	std::exception_ptr eptr;
	try {
		std::string name{ "necati" };
		name.at(10) = 'x';  //throws std::out_of_range
	}
	catch (...) {
		eptr = std::current_exception(); // capture
	}
	handle_stored_exception(eptr);
} // destructor for std::out_of_range called here, when the eptr is destroyed
