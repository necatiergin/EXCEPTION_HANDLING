#include <type_traits>

class Myclass {

};

int main()
{
	const auto b1 = std::is_nothrow_default_constructible_v<Myclass>;
	const auto b2 = std::is_nothrow_copy_constructible_v<Myclass>;
	const auto b3 = std::is_nothrow_move_constructible_v<Myclass>;
	const auto b4 = std::is_nothrow_copy_assignable_v<Myclass>;
	const auto b5 = std::is_nothrow_move_assignable_v<Myclass>;
}
