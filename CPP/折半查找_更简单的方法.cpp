#include <iostream>
#include <iostream>
#include <map>
using namespace std;


int binSearch(int *a, int len, int dst)
{
    int l = -1;
    int r = len;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (dst > a[mid])
            l = mid + 1;
        else if (dst < a[mid])
            r = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 3, 5, 8, 10, 20, 60, 70, 100, 1000};
    const int len = 10;
    int dst = 900;
    int res = binSearch(a, len, dst);

    if (res != -1)
        cout << "pos:" << res << " res:" << a[res] << endl;
    else
        cout << "not find" << endl;
    
    return 0;
}