#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int LEN = 10;
const int RANGE = 50;

void bubblesort(int a[], int len);
void selectsort(int a[], int len);
void insertsort(int a[], int len);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int a[LEN];
	cout << "original array" << endl;
	for (int i = 0; i < LEN; ++i)
	{
		a[i] = rand()%RANGE + 1;
		cout << a[i] << " ";
	}

	cout << "\nafter sorted" << endl;
	bubblesort(a, LEN);
	selectsort(a, LEN);
	insertsort(a, LEN);
	for (int i = 0; i < LEN; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}

void bubblesort(int a[], int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (a[i] < a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void selectsort(int a[], int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int k = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[k] < a[j])
				k = j;
		}
		if (k != i)
		{
			int tmp = a[k];
			a[k] = a[i];
			a[i] =tmp;
		}
	}
}

void insertsort(int a[], int len)
{
	for (int i = 1; i < len; ++i)
	{
		int j = i - 1;
		int tmp = a[i];

		while ((j >= 0) && (tmp < a[j]))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
}
