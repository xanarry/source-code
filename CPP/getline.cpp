#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char str[20];
	cout << "input string" << endl;
	cin >> str;
	cout << str;
	cout << "\n---------------------" << endl;
	cout << "do it again" << endl;
	cin.getline(str, 20, '/');
	cout << str;
	return 0;
}
