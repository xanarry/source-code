#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	int a;
	cout << "input a" << endl;
	cin >> a;
	cout << "dec=" << dec << a << endl;
	cout << "hex=" << hex << a << endl;
	cout << "oct=" << oct << a << endl;
	cout << "setbase = " << setbase(16) << a << endl;

	char *p = "Chana";
	cout << setw(10) << p << endl;
	cout << setfill('-') << setw(10) << p << endl;

	double pi = 13.1415926;
	cout << "pi = " << pi << endl;
	cout << "pi = " << setprecision(3) << pi << endl;
	cout << "pi = " << setiosflags(ios::fixed) << setprecision(2) << pi << endl;

	cout << "\ninput a number" << endl;
	int d;
	cin >> d;
	cout.put(d);

	cout << "\ninput a char" << endl;
	char c;
	cin >> c;
	cout << dec << (int)c << endl;
	cout << "a string" << endl;
	char str[] = "abcdefg";
	cout << str << endl << "order by desc" << endl;
	for(int i = 6; i >= 0; i--)
	{
		cout.put(str[i]) << " ";
	}
	cout << endl;
	return 0;
}
