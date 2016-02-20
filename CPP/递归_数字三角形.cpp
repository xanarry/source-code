#include <iostream>
#include <algorithm>
using namespace std;

int a[100][100], n;

int max_sum(int i, int j)
{
    if (i == n - 1)
        return a[i][j];
    else
        return a[i][j] + max(max_sum(i + 1, j), max_sum(i + 1, j + 1));
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];

    cout << max_sum(0, 0) << endl;
    return 0;
}
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
30
*/