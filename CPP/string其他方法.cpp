#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	const char * a = "abcdefghijklmnopqrstuvwxyz";
	cout << a << endl;

	string s1(a);
	cout << "s1(a), s1 = " << s1 << endl;

	string s2(a + 23, 2);
	cout << "s2(a + 23, 2), s2 = " << s2 << endl;

	string s3(a + 4, 5);
	cout << "s3(a + 4, 5), s3 = " << s3 << endl;

	string s4(a, 4, 5);
	cout << "s4(a, 4, 5), s4 = " << s4 << endl;

	string s5(a, 4);
	cout << "s5(a, 4), s5 = " << s5 << endl;

	string s6(a, 4, 100);
	cout << "a6(a, 4, 100), s6 = " << s6 << endl;

	/*
	string s7(a, 100);抛出out_of_range异常
	cout << "s7(a, 100), s7 = " << s7 << endl;
	*/
	return 0;
}
