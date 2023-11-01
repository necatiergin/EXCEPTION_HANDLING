#include <exception>
#include <iostream>
#include <cstdlib>

void func()
{
	throw std::exception{};
}

void foo()noexcept
{
	func();
}

// foo fonksiyonu noexcept olarak nitelendiğinden çalışma zamanında exception gönderdiğinde
//derleyici terminate işlevini çağıracak. Yani aşağıdaki kodda exception yakalanamayacak.

void my_terminate(void)
{
	std::cout << "my terminate called\n";
	std::abort();
}

int main()
{
	std::set_terminate(&my_terminate);

	try {
		foo();
	}
	catch (const std::exception& ex) {
		std::cout << "hata yakalandi : " << ex.what() << "\n";
	}
}
