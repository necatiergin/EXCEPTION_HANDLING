#include <iostream>
#include <vector>
#include <exception>

class Buffer {
	constexpr static auto size{ 1'024u * 1'024u };
	char mbuffer[size];
};

int main()
{
	std::vector<Buffer*> bvec;

	try {
		for (;;) {
			bvec.push_back(new Buffer);
			std::cout << '.';
		}
	}
	catch (const std::bad_alloc& ex) {
		std::cout << "\nexception caught : " << ex.what() << '\n';
		std::cout << "size = " << bvec.size() << '\n';
	}
}
