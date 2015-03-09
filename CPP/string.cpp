#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str[5];
	for(int i = 0; i < 5; i++)
	{
		cin >> str[i];
	}

	sort(str, str+5);

	for(int i = 0; i < 5; i++)
	{
		cout << str[i] << endl;
	}
	return 0;
}
