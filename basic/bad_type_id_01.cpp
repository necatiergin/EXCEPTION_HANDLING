#include <typeinfo>
#include <iostream>

class Base {
public:
	virtual ~Base() = default;
	//...
};


class Der : public Base {
	//...
};

void foo(Base* baseptr)
{
	if (typeid (*baseptr) == typeid(Der)) {
		//...
	}
}

int main()
{
	try {
		foo(nullptr);
	}
	//catch (const std::exception& ex) {
	catch (const std::bad_typeid& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}

}
