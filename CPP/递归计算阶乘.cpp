#include <iostream>

using namespace std;

long fun(int n)
{
	if (n == 1)
		return 1;
	else
		return n*fun(n-1);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	long result = fun(n);
	cout << "the result is " << result;
	return 0;
}
