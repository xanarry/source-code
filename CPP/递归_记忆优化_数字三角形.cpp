#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100][100], n;
int m[100][100];

int max_sum(int i, int j)
{
    if (m[i][j] > -1)
        return m[i][j];
    return m[i][j] = a[i][j] + (i == n - 1 ? 0 : max(max_sum(i + 1, j), max_sum(i + 1, j + 1)));
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];

    memset(m, -1, sizeof(m));
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