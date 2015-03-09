#include <iostream>
using namespace std;

void build_max_heap(int *a, int max_size);
int find_max(int *a, int i, int max_size);
void heap_sort(int *a, int max_size);

int main(int argc, char const *argv[])
{
	const int N = 10;
	//不要下标为0的元素
	int a[N + 1] = {-1,4,1,3,2,16,9,10,14,8,7};

	//build_max_heap(a, N);

	heap_sort(a, N);

	for (int i = 1; i <= N; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

void build_max_heap(int *a, int max_size)
{
	/*最大堆从后向前构建每一个节点的秩序*/
	for (int i = max_size; i >= 1; i--)
	{
		int current = i;
		int index_of_max = i;
		//如果发现当前节点的子节点的值比它大，那么就交换他和他值最大的那个子节点的值，然后循环检查刚替换的子节点的秩序
		//check if current node need to move;
		//find_max返回当前节点子节点的最大值下标
		while ( (index_of_max = find_max(a, current, max_size)) != current) 
		{
			int temp = a[current];
			a[current] = a[index_of_max];
			a[index_of_max] = temp;
			current = index_of_max;
		}
	}
}

int find_max(int *a, int i, int max_size)
{
	int child_l = i * 2;
	int child_r = child_l + 1;
	int index_of_max = i;

	if (child_l < max_size)
	{
		if (a[child_l] > a[index_of_max])
			index_of_max = child_l;
		if (a[child_r] > a[index_of_max])
			index_of_max = child_r;
	}
	else if (child_l == max_size)
	{
		if (a[child_l] > a[i])
			index_of_max = child_l;
	}

	return index_of_max;
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