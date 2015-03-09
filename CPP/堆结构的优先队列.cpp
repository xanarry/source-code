#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int queue_size = 0;
void max_heapify(int *a, int pos);
void build_max_heap();
void insert_into(int *a, int key);
int extract_max(int *a);
void increase_key(int *a, int new_key);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
	int a[100];
	for (int i = 0; i < 100; i++)
		insert_into(a, rand() % 100);
	/*
	insert_into(a, 9);
	insert_into(a, 10);
	insert_into(a, 5);
	insert_into(a, 14);
	insert_into(a, 1);
	insert_into(a, 8);
	insert_into(a, 6);
    insert_into(a, 16);
	insert_into(a, 13);
	insert_into(a, 17);*/

	for (int i = 0; i < queue_size; i++)


        cout << a[i] << ",";
    cout << endl;

    for (int i = 0; i < 100; i++)
        cout << extract_max(a) << endl;

	return 0;
}

void max_heapify(int *a, int pos)
{
	int i = pos;
	int r = (i + 1) << 1;
	int l = r - 1;
	int largest_index = pos;

	if (l < queue_size && a[largest_index] < a[l])
		largest_index = l;

	if (r < queue_size && a[largest_index] < a[r])
		largest_index = r;

	if (largest_index != i)
	{
		int temp = a[i];
		a[i] = a[largest_index];
		a[largest_index] = temp;
		max_heapify(a, largest_index);
	}
}


void insert_into(int *a, int key)
{
    queue_size++;
	a[queue_size - 1] = -1;
	increase_key(a, key);
}

int extract_max(int *a)
{
	int max = a[0];
	a[0] = a[--queue_size];
	max_heapify(a,0);
	return max;
}

void increase_key(int *a, int new_key)
{
    int index = queue_size - 1;
	a[index] = new_key;
	int i = index;
	int parent = (i + 1) / 2 - 1;
	while (i > 0 && a[i] > a[(i + 1) / 2 - 1])
	{
		int tmp = a[(i + 1) / 2 - 1];
		a[(i + 1) / 2 - 1] = a[i];
		a[i] = tmp;

		i = (i + 1) / 2 - 1;
	}
}
