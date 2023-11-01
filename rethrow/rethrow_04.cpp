//bir exception handle edilmediğinde rethrow statement yürütülürse std::terminate işlevi çağrılır.


#include <iostream>

void nec_terminate()
{
	std::cout << "nec_terminate()\n";
	std::abort();
}

void func()
{
	throw;
}


int main()
{
	std::set_terminate(nec_terminate);
	func();
}
