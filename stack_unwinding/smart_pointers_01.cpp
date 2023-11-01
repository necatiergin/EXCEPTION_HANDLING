#include <iostream>
#include <stdexcept>

class ResourceUser {
public:
	ResourceUser()
	{
		std::cout << this << " adresindeki nesne icin kaynaklar edinildi\n";
	}

	~ResourceUser()
	{
		std::cout << this << " adresindeki nesne icin kaynaklar geri verildi\n";
	}
};


void f3()
{
	std::cout << "f3 basladi\n";

	//throw std::runtime_error{"f3 islevinde hata"};
	//yorum satirindan cikartarak tekrar derleyip calistirin
}


void f2()
{
	std::cout << "f2 basladi\n";

	auto p = new ResourceUser;
	f3();

	delete p;
	std::cout << "f2 sona erdi\n";

}

void f1()
{
	std::cout << "f1 basladi\n";
	auto p = new ResourceUser;
	f2();
	delete p;
	std::cout << "f1 sona erdi\n";
}

int main()
{
	std::cout << "main basladi\n";

	try {
		f1();
	}
	catch (const std::exception& ex) {
		std::cout << "hata yakalandi : " << ex.what() << "\n";
	}

	std::cout << "main sona eriyor\n";
}
