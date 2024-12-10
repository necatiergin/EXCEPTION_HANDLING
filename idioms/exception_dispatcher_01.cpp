#include <iostream>

class XException {
	//...
};


class YException {
	//...
};

class ZException {
	//...
};



void handle_exception()
{
	try {
		throw;
	}
	catch (const XException &) {
		std::cout << "X exception caught\n";
	}
	catch (const YException&) {
		std::cout << "Y exception caught\n";
	}
	catch (const ZException&) {
		std::cout << "Z exception caught\n";
	};
}


void foo()
{
	try {
		throw XException{};
	}
	catch (...) {
		handle_exception();
	}
}

void bar()
{
	try {
		throw YException{};
	}
	catch (...) {
		handle_exception();
	}
}


void baz()
{
	try {
		throw ZException{};
	}
	catch (...) {
		handle_exception();
	}
}

int main()
{
	foo();
	bar();
	baz();
}
