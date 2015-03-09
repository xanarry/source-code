#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char * except(string, int &);
bool aeiou(char c);

int main(int argc, char const *argv[])
{
	string a;
	string b;
	int count;
	cin >> a;
	b = except(a, count);
	cout << "new string is: " << b << endl;
	cout << "and the count of a e i o u is: " << count << endl;
	return 0;
}

char * except(string a, int &n)
{
	char *b = new char[a.size()];
	int k = 0;
	n = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		if (!aeiou(a[i]))
		{
			b[k++] = a[i];
		}
		else
			n++;
	}
	return b;
}

bool aeiou(char c)
{
	const char *str = "aeiou";
	for (int i = 0; i < 5; ++i)
	{
		if (c == str[i])
		{
			return true;
		}
	}
	return false;
}
