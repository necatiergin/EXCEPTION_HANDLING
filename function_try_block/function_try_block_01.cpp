#include <iostream>
#include <stdexcept>

struct Member {
	Member(int)
	{
		std::cout << "Member ctor throws an exception\n";
		throw std::runtime_error{ "error from member ctor" };
	}
};

class Owner {
public:
	Owner() try : mx{ 0 }
	{

	}
	catch (const std::exception& ex)
	{
		std::cout << "exception caught : " << ex.what() << '\n';
		// if no exception thrown in the catch block compiler adds a rethtow atement
		// uncomment and recompile
		//throw std::runtime_error{ "error from owner ctor" };
	}
private:
	Member mx;
};


int main()
{
	try {
		Owner ox;
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught in main : " << ex.what() << '\n';
	}
}
