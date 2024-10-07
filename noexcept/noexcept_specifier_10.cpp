#include <string>
#include <iostream>
#include <vector>
#include <chrono>

class Nec {

public:
	Nec() : ms(2'000, 'A') {}
	Nec(const Nec& other) : ms{ other.ms } {}
	//Nec(Nec&& other): ms{ std::move(other.ms) } {}
	Nec(Nec&& other)noexcept : ms{ std::move(other.ms) } {}
private:
	std::string ms;
};

int main()
{
	using namespace std::chrono;
	using namespace std;

	vector<Nec> vec(100'000);

	auto start = steady_clock::now();

	vec.resize(vec.capacity() + 1);
	auto end = steady_clock::now();

	cout << duration<double, milli>(end - start).count() << "ms\n";
}
