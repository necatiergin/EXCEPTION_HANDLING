#include <iostream>
#include <string>
#include <vector>

class Person {
public:

private:
	int m_x;
	std::string m_str;
	std::vector<int> m_vec;
};

int main()
{
	using namespace std;

	cout << boolalpha;
	
	cout << "default ctor : " << is_nothrow_default_constructible_v<Person> << '\n';
	cout << "copy ctor    : " << is_nothrow_copy_constructible_v<Person> << '\n';
	cout << "move ctor    : " << is_nothrow_move_constructible_v<Person> << '\n';
	cout << "copy assign. : " << is_nothrow_copy_assignable_v<Person> << '\n';
	cout << "move assign. : " << is_nothrow_move_assignable_v<Person> << '\n';
}
