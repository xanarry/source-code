#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[10];
	for (int i = 0; i < 10; i++) 
	{
		a[i] = i * 2;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (auto t : a)
	{
		cout << t << " ";
	}
	cout << endl;
	return 0;
}