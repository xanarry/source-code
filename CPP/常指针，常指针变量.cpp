#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	const char a[] = "hello world";
	const char *p;//常指针变量只能指向常指针
	p = a;
	cout << *p << endl;
//	*p = 'H';//不能企图对const的a做修改

	char b[] = "hello world";
	const char *q;
	q = a;
	cout << *p << endl;
//	*p = 'H';//常指针只能引用，不能更改数据

	char c[] = "hello world";
	char *r;
	r = c;
	cout << *r << endl;
	*r = 'H';
	cout << *r << endl;

	return 0;
}
