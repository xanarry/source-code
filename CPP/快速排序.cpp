#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

void swap(int *a, int *b);
void qsort(int *a, int l, int r);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	const int len = 100000;
	int *a = new int[len];
	cout << "original: [";
	for (int i = 0; i < len; i++)
	{
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << "\b]\n";

	qsort(a, 0, len - 1);

	cout << "qsorted : [";
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << "\b]\n";
	cout << "time consume:" << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}

void qsort(int *a, int l, int r)
{
	if (r - l <= 0)
		return;

	int m = (l + r) / 2;
	int pivot_index = (  a[l]>a[r] ? ( a[r]>a[m] ? r : (a[l]>a[m] ? m : l) ) : ( a[m]>a[l] ? (a[m]>a[r] ? r : m) : l )  );
	int pivot = a[pivot_index];

	swap(a[l], a[pivot_index]);

	int i = l;
	int j = r;

	while (i < j) 
	{
		while (a[j] > pivot && j > i)
			j--;
		while (a[i] <= pivot && i < j)
			i++;
		swap(a[i], a[j]);
	}

	swap(a[l], a[i]);

	qsort(a, l, i - 1);
	qsort(a, i + 1, r);
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}