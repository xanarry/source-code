#include <iostream>
using namespace std;

int add(int &a)
{
	a++;
}

int main(int argc, char const *argv[])
{
	int a = 1;
	add(a);
	cout << a;
	return 0;
}