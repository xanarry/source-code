#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int cmp(const void *p1, const void *p2)
{
	return -strcmp((char *)p2, (char *)p1);
} 

int main(int argc, char const *argv[])
{
	char a[210];
	char r[210][210];
	int t = 0;
	char *result = NULL;
	cin >> a;
	result = strtok(a, "*+.");
	while (result != NULL)
	{
		strcpy(r[t], result);
		result = strtok(NULL, "*+.");
		t++;
	}
	qsort(r, t, sizeof(r[0]), cmp);
	for (int i = 0; i < t; ++i)
	{
		cout << r[i] << endl;
	}
	return 0;
}

