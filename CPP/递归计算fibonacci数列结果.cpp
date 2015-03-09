#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n <= 2)
		return 1;
	else
		n = fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char const *argv[])
{
	cout << "input a number:";
	int num;
	cin >> num;
	cout << fibonacci(num) << endl;
	return 0;
}