#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

string add(string, string);
int main(int argc, char const *argv[])
{
	string str1, str2;
	cin >> str1 >> str2;
	string result = add(str1, str2);
	cout << result << endl;
	return 0;
}

string add(string str1, string str2)
{
	const int MAX_LEN = 100;
	int a[MAX_LEN];
	int b[MAX_LEN];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < str1.size(); i++)
	{
		a[MAX_LEN - 1 - i] = str1[str1.size() - 1 - i] - '0';
	}
	for (int i = 0; i < str2.size(); i++)
	{
		b[MAX_LEN - 1 - i] = str2[str2.size() - 1 - i] - '0';
	}

	for (int i = MAX_LEN - 1; i > 0; i--)
	{
		a[i] += b[i];
		if (a[i] >= 10)
		{
			a[i] -= 10;
			a[i - 1]++;
		}
	}
	stringstream out;//字符串流对象
	int i;
	for (i = 0; i < MAX_LEN; i++)
	{
		if (a[i] != 0)
			break;
	}
	for (int j = i; j < MAX_LEN; j++)
	{
		out << a[j];
	}
	return out.str();//返回值*/
}