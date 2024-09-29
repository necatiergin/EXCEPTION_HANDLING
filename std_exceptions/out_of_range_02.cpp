#include <map>
#include <string>
#include <iostream>

int main()
{
	std::map<std::string, int> simap{
		{"necati", 4},
		{"kaan", 7},
		{"ali", 6} };

	try {
		simap.at("veli") = 3;
	}
	//catch (const std::exception& ex) {
	//catch (const std::logic_error& ex) {
	catch (const std::out_of_range& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}
}
