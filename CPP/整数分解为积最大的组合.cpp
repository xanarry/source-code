#include <iostream>
using namespace std;

void disintegrate(int n);
long long max_value = 1;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	disintegrate(n);
	cout << endl;
	cout << max_value << endl;
	return 0;
}

void disintegrate(int n)
{
	if (n == 3 || n == 2)
	{
		cout << n << " ";
		max_value = n * max_value;
	}
	else 
	{
		int temp = n / 2;
		disintegrate(temp);
		disintegrate(n - temp);
	}
}