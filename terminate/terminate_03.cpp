#include <iostream>
#include <exception>

class Nec {
public:
	Nec(int x)
	{
		if (x % 5 == 0)
			throw 1;
		//...
	}
};


void myterminate()
{
	std::cout << "function myterminate called!\n";
	std::exit(EXIT_FAILURE);
}

auto f = std::set_terminate(myterminate);

Nec gnec{ 25 };

int main()
{

}
