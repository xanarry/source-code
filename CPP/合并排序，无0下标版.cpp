#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void mergesort(int *a, int l, int r);
void merge(int *a, int l, int m, int r);
int main(int argc, char const *argv[])
{
	const int N = 10;
	int a[N + 1] = {-1,7,3,0,4,2,6,1,9,5,8};
	for (int i = 1; i <= N; i++)
		cout << a[i] << " ";
	cout << endl;
	
	mergesort(a, 1, 10);

	for (int i = 1; i <= N; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}

void mergesort(int *a, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergesort(a, start, mid);
		mergesort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

void merge(int *a, int l, int m, int r)
{
	int lenl = m - l + 1;
	int lenr = r - m;
	int temp[r - l + 1];

	//设置数组的起点
	int posl = l;
	int posr = m + 1;
	int pos = 0;

	while (posl <= m && posr <= r)
	{
		if (a[posl] <= a[posr])
			temp[pos++] = a[posl++];
		else
			temp[pos++] = a[posr++];
	}

	while (posl <= m)
		temp[pos++] = a[posl++];
	while (posr <= r)
		temp[pos++] = a[posr++];

	int index = 0;
	for (int i = l; i <= r; i++)
		a[i] = temp[index++];
}