#include <iostream>

void foo(int x)
{
	if (x % 2 == 0) {
		throw 'e';	  //exception object type is char
	}
}

int main()
{
	try {
		foo(4);		//uncaught exception
	}
	catch (int i) {
		std::cout << "exception caught: i = " << i << '\n';
	}
}
