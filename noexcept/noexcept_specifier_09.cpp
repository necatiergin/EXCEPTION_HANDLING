#include <type_traits>
#include <string>

template <typename T>
void func(T) noexcept(std::is_nothrow_move_assignable_v<T>)
{
	//...
}


class Myclass {};

int main()
{
	constexpr bool b1 = noexcept(func(12));
	constexpr bool b2 = noexcept(func(Myclass{}));

}
