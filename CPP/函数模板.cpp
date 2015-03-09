#include <iostream>
using namespace std;

template<typename T>
T max(T a, T b, T c)
{
	if(a < b)
		a = b;
	if(a < c)
		a = c;
	return a;
}

int main(int argc, char const *argv[])
{
	int a, b, c;
	cout << "input 3 int num:";
	cin >> a >> b >> c;
	cout << "max = " << max(a, b, c) << endl;

	cout << "-----------------------------" << endl;
	float i, j, k;
	cout << "input 3 float num:";
	cin >> i >> j >> k;
	cout << "max = " << max(i, j, k) << endl;
	return 0;
}
