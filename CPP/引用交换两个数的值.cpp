#include <iostream>
using namespace std;

void inline swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}
int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a >> b;
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}
