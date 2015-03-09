
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int a[100];
void merge_sort(int *a, int start, int end);
void merge(int *a, int l, int m, int r);

int main(int argc, char const *argv[])
{
	const int len = 10;
//	int a[len] = {3,1,6,2,8,1,7,0,9,4};
	int *a = new int[len];
	cout << "original array:" << endl;
	for (int i = 0; i < len; i++)
		a[i] = rand() % 10;
	//	cout << a[i] << " ";
	cout << endl << endl;

	merge_sort(a, 0, len);

	cout << "after merge_sort" << endl;
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

void merge_sort(int *a, int start, int end)
{
/*	cout << "[";
	for (int i = start; i < end; i++)
		cout << a[i] << ",";
	cout << "\b]" << endl;*/

	if (start + 1 < end)
	{
		int mid = (start + end) / 2;
		merge_sort(a, start, mid);
		merge_sort(a, mid, end);
		merge(a, start, mid, end);
	}
	
}

void merge(int *a, int l, int m, int r)
{
	
/*	cout << "\nmerge start---------------" << endl;
	cout << "l=" << l << " m=" << m << " r=" << r << endl;
	cout << "in array" << endl;
	for (int i = l; i < r; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

    int l_len = m - l;
    int r_len = r - m;

    int left[l_len];
    int right[r_len];

    int i = 0, index = 0;
    for (i = l, index = 0; i < m; i++)
        left[index++] = a[i];

    for (i = m, index = 0; i < r; i++)
        right[index++] = a[i];

    int j = 0, k = 0;
    i = l;
    while (j < l_len && k < r_len)
    {
        if (left[j] <= right[k])
            a[i++] = left[j++];
        else
            a[i++] = right[k++];
    }

    while (k < r_len)
        a[i++] = right[k++];

    while (j < l_len)
        a[i++] = left[j++];

/*    cout << "out array" << endl;
    for (int i = l; i < r; i++)
    	cout << a[i] << " ";
    cout << endl;
    cout << "merge end----------------" << endl << endl;*/
}