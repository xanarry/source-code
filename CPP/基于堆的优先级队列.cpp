#include <iostream>
using namespace std;

const int max_size = 100;

void max_heapify(int *a, int i, int heap_size);
void build_max_heap(int *a, int heap_size);
int maximum(int *a);
void insert(int *a, int n, int &heap_size);
void extract_max(int *a, int &heap_size);
void increase_key(int *a, int i, int k);
void swap(int *a, int *b);
void display(int *a, int &heap_size);

int main(int argc, char const *argv[])
{
	int heap_size = 0;
	int a[max_size + 1];
	

	cout << "insert(a, 23, heap_size);"; insert(a, 3, heap_size);
	display(a, heap_size);

	cout << "increase_key(a, 1, 90);"; increase_key(a, 1, 90);
	display(a, heap_size);

	cout << "insert(a, 1, heap_size);"; insert(a, 1, heap_size);
	display(a, heap_size);

	cout << "insert(a, 2, heap_size);"; insert(a, 2, heap_size);
	display(a, heap_size);

	cout << "insert(a, 4, heap_size);"; insert(a, 4, heap_size);
	display(a, heap_size);

	cout << "insert(a, 5, heap_size);"; insert(a, 5, heap_size);
	display(a, heap_size);

	cout << "insert(a, 9, heap_size);"; insert(a, 9, heap_size);
	display(a, heap_size);

	cout << "courrent max = " << maximum(a) << endl;
	cout << "extract_max(a, heap_size);"; extract_max(a, heap_size);
	display(a, heap_size);

	cout << "current max = " << maximum(a) << endl;
	cout << "extract_max(a, heap_size);"; extract_max(a, heap_size);

	display(a, heap_size);
	return 0;
}

void build_max_heap(int *a, int heap_size)
{
	int i = heap_size;
	while (i >= 1)
		max_heapify(a, i--, heap_size);
}

void max_heapify(int *a, int i, int heap_size)
{
	int child_l = i * 2;
	int child_r = child_l + 1;
	int index_of_max = i;

	if (child_l < heap_size)
	{
		if (a[child_l] > a[index_of_max])
			index_of_max = child_l;
		if (a[child_r] > a[index_of_max])
			index_of_max = child_r;
	}
	else if (child_l == heap_size && a[child_l] > a[index_of_max])
		index_of_max = child_l;

	if (index_of_max != i)
	{
		swap(a[i], a[index_of_max]);
		max_heapify(a, index_of_max, heap_size);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int *a, int n, int &heap_size)
{
	if (max_size < heap_size + 1)
	{
		cout << "heap overflow" << endl;
		return;
	}
	heap_size++;
	a[heap_size] = n;
	build_max_heap(a, heap_size);
}

int maximum(int *a)
{
	return a[1];
}

void increase_key(int *a, int i, int k)
{
	if (k < a[i])
	{
		cout << "new key is smaller than current key" << endl;
		return;
	}
	a[i] = k;
	int parent;
	while (i > 1 && a[i] > a[parent = i / 2])
	{
		swap(a[i], a[parent]);
		i = parent;
	}
}

void extract_max(int *a, int &heap_size)
{
	a[1] = a[heap_size];
	heap_size--;
	max_heapify(a, 1, heap_size);
}

void display(int *a, int &heap_size)
{
	for (int i = 1; i <= heap_size; i++)
		cout << a[i] << " ";
	cout << endl;
}