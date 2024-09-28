//noexcept operand is unevaluated.

#include <climits>

int main()
{
	int a[5]{};
	int* ptr{};
	int x{};

	constexpr auto b1 = noexcept(a[10]);   // true (no - ub)
	constexpr auto b2 = noexcept(*ptr);	   //true (no - ub)
	constexpr auto b3 = noexcept(x << (sizeof(int) * CHAR_BIT));   //true (no - ub)
}
