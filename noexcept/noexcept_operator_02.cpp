#include <iostream>

void f1();
void f2()noexcept;
auto fx = [] {};
auto fy = []()noexcept {};


class Nec {
public:
	Nec() {};
	~Nec() {};
};
int main()
{
	std::cout << std::boolalpha;
	std::cout << noexcept(f1()) << '\n';
	std::cout << noexcept(f2()) << '\n';
	std::cout << noexcept(fx()) << '\n';
	std::cout << noexcept(fy()) << '\n';
	std::cout << noexcept(Nec{}) << '\n';
	std::cout << noexcept(std::declval<Nec>().~Nec()) << '\n';
	constexpr auto flag = noexcept(fx()); //gecerli
}
