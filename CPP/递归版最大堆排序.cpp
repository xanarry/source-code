#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

void max_heapify(int *a, int i, int max_size);
void build_max_heap(int *a, int max_size);
void heap_sort(int *a, int max_size);

int main(int argc, char const *argv[])
{
	const int N = 10;
	//不要下标为0的元素
	int a[N + 1] = {-1,4,1,3,2,16,9,10,14,8,7};
	
//	build_max_heap(a, N);

	heap_sort(a, N);
	
	for (int i = 1; i <= N; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

void heap_sort(int *a, int max_size)
{
	while (max_size > 1)
	{
		build_max_heap(a, max_size);
		int temp = a[1];
		a[1] = a[max_size];
		a[max_size] = temp;
		max_size--;
	}
}

void build_max_heap(int *a, int max_size)
{
	for (int i = max_size; i >= 1; i--)
		max_heapify(a, i, max_size);
}

void max_heapify(int *a, int i, int max_size)
{
	int index_of_max = i;
	int child_L = i * 2;
	int child_R = child_L + 1;

	//有两个子节点
	if (child_L < max_size)
	{
		//@可能两个子节点的值都比跟节点的值大
		if (a[child_L] > a[i])
			index_of_max = child_L;
		if (a[child_R] > a[index_of_max])
			index_of_max = child_R;
	}
	//有一个子节点，并且只存在只有左子节点的情况
	else if (child_L == max_size)
	{
		if (a[child_L] > a[i])//只比较一个数
			index_of_max = child_L;
	}
	if (index_of_max != i)
	{
		int temp = a[i];
		a[i] = a[index_of_max];
		a[index_of_max] = temp;

		max_heapify(a, index_of_max, max_size);
	}
}