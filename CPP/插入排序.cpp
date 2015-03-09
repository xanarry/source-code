#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[10] = {3,2,1,4,6,5,8,7,9,0};
	for (int i = 0; i < 10; i++) 
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 1; i < 10; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && key < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}