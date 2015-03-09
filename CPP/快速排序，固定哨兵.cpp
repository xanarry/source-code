#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
void swap(int *a, int *b);
void quicksort(int *a, int l, int r);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	const int n = 10;
	int a[n] = {7,3,0,4,2,6,1,9,5,8};
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";

	}
	cout << endl;

	quicksort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "time consume:" << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}

void quicksort(int *a, int l, int r)
{
	int pivot = a[l];
	int i = l + 1;
	int j = r;

	while (i < j) 
	{
		while (j > i && a[j] > pivot)
			j--;
		while (j > i && a[i] <= pivot)
			i++;
		swap(a[i], a[j]);
	}
	swap(a[l], a[i]);	

	if (i - 1 > l)
		quicksort(a, l, i - 1);
	if (r - 1 > i)
		quicksort(a, i + 1, r);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}