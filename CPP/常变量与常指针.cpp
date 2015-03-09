#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	const int a = 10;
//	int *p = &a;
//	cout << *p << endl;//企图将常指针给普通指针，非法，无法通过编译
	const int *p1;
	p1 = &a;
	cout << *p1 << endl;
	return 0;
}