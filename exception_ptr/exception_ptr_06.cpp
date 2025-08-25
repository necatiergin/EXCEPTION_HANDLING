#include <iostream>
#include <string>
#include <exception>

struct NecError {
	std::string msg;
};

std::exception_ptr make_nec_error(std::string str)
{
	return std::make_exception_ptr(NecError{ std::move(str) });
}

void foo(std::exception_ptr eptr)
{
	std::rethrow_exception(eptr);
	//...
}

int main()
{
	try {
		foo(make_nec_error("nec error!"));
	}
	catch (const NecError& ex) {
		std::cout << "exception caught: " << ex.msg << '\n';
	}
}
