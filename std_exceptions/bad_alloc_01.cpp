#include <iostream>
#include <vector>
#include <new>

int main()
{
	std::vector<int*> ivec;
	ivec.reserve(1000);

	try {
		for (int i = 0; i < 1000; ++i) {
			ivec.push_back(new int[1024 * 1024]);
			std::cout.put('.');
		}
	}
	catch (const std::bad_alloc& ex) {
	//catch (const std::exception& ex) {
		std::cout << "\nexception caught: " << ex.what() << '\n';
	}
}
