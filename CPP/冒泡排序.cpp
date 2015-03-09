#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 30;

void bubblesort(int a[], int len)
{
	int i, j;
	int tmp;
	for (int i = 0; i < len-1; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int a[N];
	for (int i = 0; i < N; ++i)
	{
		a[i] = rand()%N + 1;
		cout << a[i] << " ";
	}
	cout << "\nbubblesorted" << endl;
	bubblesort(a, N);
	for (int i = 0; i < N; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}
