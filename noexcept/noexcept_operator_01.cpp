//noexcept operand is unevaluated.
#include <climits>

int main()
{
	int a[5]{};
	int* ptr{};
	int x{};

	constexpr auto b1 = noexcept(a[10]);
	constexpr auto b2 = noexcept(*ptr);
	constexpr auto b3 = noexcept(x << (sizeof(int) * CHAR_BIT));
}
