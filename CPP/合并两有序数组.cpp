#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void merge(int *a, int l, int m, int r)
{
    int l_len = m;
    int r_len = r - m;

    int left[l_len];
    int right[r_len];

    for (int i = 0; i < m; i++)
        left[i] = a[i];

    for (int i = m; i < r; i++)
        right[i - r_len] = a[i];

    int i = 0, j = 0, k = 0;
    while (j < l_len && k < r_len)
    {
        if (left[j] <= right[k])
            a[i++] = left[j++];
        else
            a[i++] = right[k++];
    }

    if (j == l_len) 
    {
        while (k < r_len)
            a[i++] = right[k++];
    }

    if (k == r_len)
    {
        while (j < l_len)
            a[i++] = left[j++];
    }
}


int main(int argc, char const *argv[])
{
    int a[10] = {1,3,5,7,9, 2,4,6,8,10};
    merge(a, 0, 5, 10);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
