//yakaladığımız hata nesnesini değiştirip (set edip) onu yeniden gönderebiliriz (rethrow edebiliriz.)

#include <string>

class MyException {
public:
	// ...
	void add_info(const std::string& info);
	// ...
};

void f()
{
	try {
		// ...
	}
	catch (MyException& e) {
		e.add_info("f() failed");
		throw;
	}
}
