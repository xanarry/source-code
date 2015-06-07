#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
void swap(int *a, int *b);
void quicksort(int *a, int l, int r);

const int len = 1000000;
int a[len];
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	for (int i = 0; i < len; i++)
	{
		a[i] = rand() % 100 + 1;
	//	cout << a[i] << " ";
	}
	cout << endl;

	quicksort(a, 0, len - 1);

//	for (int i = 0; i < len; i++)
//		cout << a[i] << " ";
//	cout << endl;
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