#include <type_traits>
#include <vector>

class Myclass {
public:
	//...
	Myclass(const Myclass&)noexcept = default;
private:
	std::vector<int> mvec;
};

int main()
{
	const auto b = std::is_nothrow_copy_constructible_v<Myclass>;
}
