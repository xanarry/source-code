#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a >> b;
	int result = a;
	for (int i = 0; i < b - 1; i++)
	{
		result = add(a, result);
	}
	cout << result << endl;
	return 0;
}

