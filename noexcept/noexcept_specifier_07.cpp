void foo()noexcept;
void func();

int main()
{
	void (*fp1)() = &foo;
	void (*fp2)()noexcept = &foo;
	//void (*fp3)()noexcept = &func; //invalid
}
