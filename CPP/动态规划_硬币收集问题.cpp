#include <iostream>
#include <algorithm>
using namespace std;

int c[100][100];
int v[100][100];

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)//当前位置永远从上面和左边两个位置来, 取最大值并加上当前位置的个数
            v[i][j] = max(v[i - 1][j], v[i][j - 1]) + c[i][j];

    cout << v[m][n] << endl;
    return 0;
}

/*
3 3
1 3 2
2 4 1
2 1 3
12

5 6
0 0 0 0 1 0
0 1 0 1 0 0
0 0 0 1 0 1
0 0 1 0 0 1
1 0 0 0 1 0
5
*/