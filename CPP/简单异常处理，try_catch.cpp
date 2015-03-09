#include <iostream>
#include <cmath>
using namespace std;

double triangle(double a, double b, double c);

int main(int argc, char const *argv[])
{
	double a, b, c;
	cout << "input a b c" << endl;
	cin >> a >> b >> c;
	try
	{
		while(a > 0 && b > 0 && c > 0)
		{
			cout << triangle(a, b, c) << endl;
			cin >> a >> b >> c;
		}
	}
	catch(double)
	{
		cout << "a = " << a << " b = " << b << " c = " << c << " is not a triangle" << endl;
	}
	cout << "end" << endl;
	return 0;
}

double triangle(double a, double b, double c)
{
	double s = (a + b + c) / 2;
	if(a + b <= c || a + c <= b || b + c <= a)
		throw a;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
