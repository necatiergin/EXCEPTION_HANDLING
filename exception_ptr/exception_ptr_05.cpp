// if an empty exception_ptr is thrown by std::rethrow_exception
// std::bad_exception is thrown 

#include <iostream>
#include <exception>

int main()
{
	try {
		auto eptr = std::current_exception();
		std::rethrow_exception(eptr); // throw std::bad_exception
	}
	catch (const std::bad_exception& ex) {
	//catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}
}
