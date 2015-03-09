#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum = 0, j = 0;
	char a[250];
	char obj[3];
	cin >> a;
	for (int i = 0; i < strlen(a); i += 2)
	{
		obj[0] = a[i];
		obj[1] = a[i+1];
		obj[2] = '\0';
		if (!strcmp(obj, "ит"))
		{
			sum++;
		}
	}
	if (sum%2 != 0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
