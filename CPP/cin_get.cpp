#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{/*
	cout << "standard cin.get()" << endl;
	char c;
	while((c = cin.get()) != EOF)
	{
		cout.put(c);
	}

	cout << "one paramerter" << endl;
	while(cin.get(c))
	{
		cout.put(c);
	}
*/
	cout << "full paramerter" << endl;
	char str[20];
	cout << "please input a sentence now" << endl;
	cin.get(str, 10, '0');//指定将输入的字符放到数组str中，遇到'0'后截断，数组长度为10
	cout << str;
	return 0;
}
