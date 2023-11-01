#include <string>
#include <iostream>
#include <vector>

class Sentence {
public:
	Sentence() = default;
	Sentence(const char* ps) : m_s{ ps } {}
	Sentence(const Sentence& other) : m_s{ other.m_s }
	{
		std::cout << "copy ctor\n";
	}
	//Sentence(Sentence&& other)
	Sentence(Sentence&& other)noexcept
		: m_s{ std::move(other.m_s) }
	{
		std::cout << "move ctor\n";
	}

private:
	std::string m_s;
};

int main()
{
	std::vector<Sentence> svec{
		"Consuetudinis magna vis est",
		"Homines quod volunt credunt",
		"Hostium munera, non munera" };

	std::cout << "svec.size() = " << svec.size() << "\n";
	std::cout << "svec.capacity() = " << svec.capacity() << "\n";

	//svec.resize(svec.capacity() + 1);
	svec.push_back("Factis ut credam facis");
}
