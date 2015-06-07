#include <iostream>
using namespace std;

void min_heapity(int *a, int i, int max_size);
void build_min_heap(int *a, int max_size);
void heap_sort(int *a, int max_size);

int main(int argc, char const *argv[])
{
	const int N = 10;
	//不要下标为0的元素
	int a[N + 1] = {-1,4,1,3,2,16,9,10,14,8,7};
	heap_sort(a, N);
	
	for (int i = 1; i <= N; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

void min_heapity(int *a, int i, int max_size)
{
	int child_L = i * 2;
	int child_R = child_L + 1;
	int index_of_min = i;

	if (child_L < max_size)
	{
		if (a[child_L] < a[index_of_min])
			index_of_min = child_L;
		if (a[child_R] < a[index_of_min])
			index_of_min = child_R;
	}
	else if (child_L == max_size)
	{
		if (a[child_L] < a[i])
			index_of_min = child_L;
	}

	if (index_of_min != i)
	{
		int temp = a[i];
		a[i] = a[index_of_min];
		a[index_of_min] = temp;
		min_heapity(a, index_of_min, max_size);
	}
}

void build_min_heap(int *a, int max_size)
{
	for (int i = 1; i <= max_size; i++)
		min_heapity(a, i, max_size);
}

void heap_sort(int *a, int max_size)
{
	while (max_size > 1)
	{
		build_min_heap(a, max_size);
		int temp = a[1];
		a[1] = a[max_size];
		a[max_size] = temp;
		max_size--;
	}
}