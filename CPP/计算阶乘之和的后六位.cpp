#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int sum = 0;
	const int MOD = 1000000;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int fac = 1;
		for (int j = 1; j <= i; j++)
		{
			fac = (fac * j) % MOD;
		}
		sum = (sum + fac) % MOD;
	}
	cout << sum << endl;
//	cout << "time consume: " << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}