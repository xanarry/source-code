#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int sum = 0;
	int count = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	int in;
	while (cin >> in)
	{
		sum += in;
		if (in > max)
			max = in;
		if (in < min)
			min = in;
		count++;
	}
	cout << "sum = " << sum << endl;
	cout << "num count = " << count << endl;
	cout << "average = " << (double)sum / count << endl;
	return 0;
}