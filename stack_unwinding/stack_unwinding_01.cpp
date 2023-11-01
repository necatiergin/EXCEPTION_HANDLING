#include <iostream>
#include <thread>
#include <stdexcept>

struct A {
	~A()
	{
		std::cout << "A destructor\n";
	}
};

struct B {
	~B()
	{
		std::cout << "B destructor\n";
	}
};

struct C {
	~C()
	{
		std::cout << "C destructor\n";
	}
};

void baz()
{
	C cx;
	throw std::runtime_error{"runtime error!\n"};
}

void bar()
{
	B bx;
	baz();
}

void foo()
{
	A ax;
	bar();
}

int main()
{
	try {
		foo();
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}
}
