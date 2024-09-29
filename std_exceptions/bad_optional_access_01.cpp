#include <optional>
#include <iostream>

int main()
{
	std::optional<int> x;

	try {
		[[maybe_unused]] auto val = x.value();
	}
	catch (const std::bad_optional_access& ex) {
	//catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}
}
