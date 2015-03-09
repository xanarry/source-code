#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	int t_max(int a, int b);
	int t_max(int a, int b, int c);
	cout << "first input two nums:";
	cin >> a >> b;
	cout << t_max(a,b) << endl;

	cout << "input three nums:";
	cin >> a >> b >> c;
	cout << t_max(a,b,c) << endl;
	return 0;
}

int t_max(int a, int b)
{
	return (a > b? a:b);
}

int t_max(int a, int b, int c)
{
	if(a < b)
		a = b;
	if(a < c)
		a = c;
	return c; 
}

