#include <stdexcept>
#include <iostream>

class Member {
public:
	Member(int x)
	{
		if (x % 2 != 0)
			throw std::invalid_argument{ "Member ctor argument should be even!" };
		//...
	}
	~Member()
	{
		std::cout << "Member destructor\n";
	}
};


class Owner {
public:
	Owner() = default;
	Owner(int a) : mx{a} {}
	~Owner()
	{
		std::cout << "Owner destructor\n";
	}
private:
	Member mx{0};
};

int main()
{
	try {
		Owner x{ 3 };
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}
}
