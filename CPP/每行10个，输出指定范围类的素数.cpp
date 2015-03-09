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
	int t = 0;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		if(t == 10)
		{
			t = 0;
			cout << endl;
		}
		if (IsPrime(i))
		{
			t++;
			cout << i << " ";
		}
		
	}
	return 0;
}
