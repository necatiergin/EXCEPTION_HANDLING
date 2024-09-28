#include <iostream>
#include <stdexcept>


struct Myclass {
	Myclass(int x)
	{
		std::cout << "Myclass(int)\n";

		if (x % 2 == 0)
			throw std::invalid_argument("odd argument!");
	}

	~Myclass()
	{
		std::cout << "Myclass destructor\n";
	}
};

int main()
{
	try {
		Myclass mx(12);  
		//destructor will not be called
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}
}
