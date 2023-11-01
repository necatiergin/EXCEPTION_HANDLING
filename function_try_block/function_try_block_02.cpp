#include <iostream>
#include <string>
#include <exception>

int func(std::string &s)
try {
	//...
	return 0;
}
catch (std::exception& ex) {
	const auto len = s.length(); //s is visible here
	std::cout << "exception caught : " << ex.what() << '\n';

	return 1; //catch block may have a return statement
}
