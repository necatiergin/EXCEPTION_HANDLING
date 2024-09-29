#include <iostream>
#include <typeinfo>

struct Base {
	virtual ~Base() = default;
};

class Nec : public Base {};
class Erg : public Base {};

int main()
{
	Nec nec;
	Base& baseref{ nec };

	try {
		[[maybe-unused]] Erg& e = dynamic_cast<Erg&>(baseref);
	}
	catch (const std::bad_cast& ex) {
		//catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}

}
