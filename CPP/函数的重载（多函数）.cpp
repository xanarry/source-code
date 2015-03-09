#include <iostream>
using namespace std;

	int get_max(int a, int b, int c)
	{
		if(a < b)
			a = b;
		if(a < c)
			a = c;
		return a;
	}

	float get_max(float a, float b, float c)
	{
		if(a < b)
			a = b;
		if(a < c)
			a = c;
		return a;
	}

	long get_max(long a, long b, long c)
	{
		if(a < b)
			a = b;
		if(a < c)
			a = c;
		return a;
	}

int main(int argc, char const *argv[])
{
	int i1, i2, i3;

	cout << "input three int nums:";
	cin >> i1 >> i2 >> i3;
	int i_max = get_max(i1, i2, i3);
	cout << 1 << "th is:" << i_max << endl;

	long l1, l2, l3;
	cout << "input three long nums:";
	cin >> l1 >> l2 >> l3;
	long l_max = get_max(l1, l2, l3);
	cout << 2 << "th is:" << l_max << endl;

	float f1, f2, f3;
	cout << "input three float nums:";
	cin >> f1 >> f2 >> f3;
	float f_max = get_max(f1, f2, f3);
	cout << 3 << "th is:" << f_max << endl;
	return 0;
}
