#include <iostream>
#include <type_traits>

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
