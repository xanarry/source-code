#include <iostream>
#include <strstream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	char c[100];//define a char array to story a string
	long sum = 0;//initialize sum equel to 0
	cout << "please input a expression" << endl;
	cin >> c;//input a expression
	int count = 0;//define count to record how name numbers the input string has

	for(int i = 0; i < strlen(c); i++)
	{
		if(c[i] == '+')
		{
			c[i] = ' ';//turn "+" to " "
			count++;
		}
	}
	count += 1;//fact is number is one more than "+"
	istrstream strin(c, sizeof(c));//create the string stream object with char array
	long a[count];
	for(int i = 0; i < count; i++)
	{
		strin >> a[i];//extract date to a integeral array
	}
	for(int i = 0; i < count; i++)
	{
		sum += a[i];//suming
	}

	for(int i = 0; i < strlen(c); i++)
	{

		if(c[i] == ' ')
			cout << '+';
		else
			cout << c[i];
	}
	cout << "=" << sum << endl;//out info
	return 0;
}
