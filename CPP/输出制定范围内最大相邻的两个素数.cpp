#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(long n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	long n;
	cin >> n;
	for (long i = n; i >= 2; --i)
	{
		if (IsPrime(i) && IsPrime(i-2))
		{
			cout << i-2 << " " << i << endl;
			break;
		}
	}
	return 0;
}
