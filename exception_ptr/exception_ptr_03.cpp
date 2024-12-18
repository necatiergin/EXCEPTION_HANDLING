#include <vector>
#include <exception>
#include <mutex>
#include <iostream>

std::vector<std::exception_ptr> g_ex_vec;
std::mutex g_mutex;

void f1() {	throw std::runtime_error{ "exception from f1" };}
void f2() {	throw std::runtime_error{ "exception from f2" };}
void f3() {	throw std::runtime_error{ "exception from f3" };}


void th_f1()
{
	try {
		f1();
	}
	catch (...) {
		std::lock_guard<std::mutex> guard{ g_mutex };
		g_ex_vec.push_back(std::current_exception());
	}
}
//----------------------------------------------------------------------------------------------------
void th_f2()
{
	try {
		f2();
	}
	catch (...) {
		std::lock_guard<std::mutex> guard{ g_mutex };
		g_ex_vec.push_back(std::current_exception());
	}
}

void th_f3()
{
	try {
		f3();
	}
	catch (...) {
		std::lock_guard<std::mutex> guard{ g_mutex };
		g_ex_vec.push_back(std::current_exception());
	}
}
//----------------------------------------------------------------------------------------------------
int main()
{
	{
		std::jthread t1(th_f1);
		std::jthread t2(th_f2);
		std::jthread t3(th_f2);
	}

	for (auto const& ex : g_ex_vec) {
		try
		{
			if (ex != nullptr)
				std::rethrow_exception(ex);
		}
		catch (std::exception const& ex)
		{
			std::cout << "exception caught: " << ex.what() << '\n';
		}
	}
}
