#include <iostream>
#include <algorithm>
using namespace std;

int a[1001][1001];
int n;
long maxsum(int i, int j)
{
    if (i == n)
        return a[i][j];
    else
        return max(maxsum(i + 1, j), maxsum(i + 1, j + 1)) + a[i][j];
}

int main(int argc, char const *argv[])
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                cin >> a[i][j];
        cout << maxsum(1, 1) << endl;
    }
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