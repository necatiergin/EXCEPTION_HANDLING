#include <iostream>

struct Nec {
	void foo() noexcept
	{
		std::cout << "Nec::foo()\n";
	}
};

int main()
{
	// unevaluated context
	constexpr auto b = noexcept(Nec{}.foo());
	//
}
