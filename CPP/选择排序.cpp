#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;
void selectsort(int a[], int len)
{
	int i, j, k, l, t;
	for (i = 0; i < len - 1; ++i)
	{
		k = i;
		for (j = i + 1; j < len; ++j)
		{
			if (a[j] < a[k])
				k = j;
		}
		if (k != i)
		{
			t = a[k];
			a[k] = a[i];
			a[i] = t;
		}
	}

}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int a[N];
	for (int i = 0; i < N; ++i)
	{
		a[i] = rand()%10;
		cout << a[i] << " ";
	}
	selectsort(a, N);
	cout << "\nselectsorted" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
