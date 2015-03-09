#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream out("test.txt");
	int a, b;
	cout << "input two number:";
	cin >> a >> b;
	out << a << " + " << b << " = " << a + b << endl;
	ifstream in("test.txt");
	string ln;
	while (getline(in, ln))
	cout << ln << endl;
	cout << "operate seccessfull, please check \"test.txt\"" << endl;
	return 0;
}
