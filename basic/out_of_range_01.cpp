#include <typeinfo>
#include <iostream>
#include <vector>

int main()
{
	std::vector vec{ 1, 2, 3, 4,  5 };

	try {
		const auto x = vec.at(5);
		//...
	}
	//catch (const std::exception& ex) {
	//catch (const std::logic_error& ex) {
	catch (const std::out_of_range& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}
}
