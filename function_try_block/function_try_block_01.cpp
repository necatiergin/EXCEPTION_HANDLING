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
		std::cout << "hata yakalandi: " << ex.what() << '\n';
		// function try bloğunu izleyen catch bloğu içinde eğer exception
		// gonderilmez ise derleyici bloğun sonuna rethrow statement ekliyor
		//yorum satirindan cikartip tekrar derleyin
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
		std::cout << "hata yakalandi : " << ex.what() << '\n';
	}
}
