#include <string>
#include <iostream>

int main()
{
	using namespace std;

	string str;
	auto max_sz = str.max_size();

	try {
		str.assign(max_sz + 10, 'a');
	}
	catch (const std::length_error& ex) {
	//catch (const std::logic"_error& ex) {
	//catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}

}
