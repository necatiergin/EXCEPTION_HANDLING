#include <iostream>

void foo()
{
	throw 5;
}

void bar()
{
	try {
		foo();
	}
	catch (int& x) {
		std::cout << "exception caught in function foo\n";
		std::cout << "the address of the exception object is: " << &x << '\n';
		x++;
		throw;
	}
}

int main()
{
	try {
		bar();
	}
	catch (const int& a) {
		std::cout << "exception caught in function main\n";
		std::cout << "the address of the exception object is: " << &a << '\n';
		std::cout << "a = " << a << '\n';
	}
}
