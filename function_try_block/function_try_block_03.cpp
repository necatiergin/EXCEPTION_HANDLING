#include <iostream>
#include <exception>

struct Nec {
	Nec() = default;
	~Nec() = default;
	Nec(const Nec&)
	{
		throw std::runtime_error{"Nec copy ctor exception!"};
	}
};

int func(Nec)
try {
	//...
	return 0;
}
catch (std::exception& ex) {
	std::cout << "exception caught : " << ex.what() << '\n';
	//cannot catch exception thrown by  function parameter
}

int main()
{
	Nec nec;

	func(nec);
}
