void bar();
void baz();

// no exception gurantee 
// foo may leak resource if new expression throws bad allovc

void foo(int n)
{
	int* p = new int[n];

	bar();
	baz();

	delete p;
}