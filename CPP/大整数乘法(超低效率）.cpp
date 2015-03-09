#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>

using namespace std;

char * add(char* str1, char* str2)
{
	const int MAX_LEN = 10000;
	int a[MAX_LEN];
	int b[MAX_LEN];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < strlen(str1); i++)
	{
		a[MAX_LEN - 1 - i] = str1[strlen(str1) - 1 - i] - '0';
	}
	for (int i = 0; i < strlen(str2); i++)
	{
		b[MAX_LEN - 1 - i] = str2[strlen(str2) - 1 - i] - '0';
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
	char t[10000];
	int j = 0;
	int start = 0;
	for (int i = 0; i < MAX_LEN; i++)
	{
		if (a[i] != 0)
		{
			start = i;
			break;
		}
	}
	for (int i = start; i < MAX_LEN; i++)
	{
		t[j++] = a[i] + 48;
	}
	t[j] = '\0';
	return t;
}

int main(int argc, char const *argv[])
{
	char str1[1000], str2[1000];
	cin >> str1 >> str2;

	int t = atoi(str2);
	char result[10000];
	strcpy(result, str1);
	for (int i = 0; i < t-1; i++)
	{
		strcpy(result, add(str1, result));
	}
	cout << result << endl;
	return 0;
}