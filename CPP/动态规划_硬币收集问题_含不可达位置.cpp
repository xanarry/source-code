#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int c[100][100];
int v[100][100];

int main(int argc, char const *argv[])
{
    memset(c, -1, sizeof(c));
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)//当前位置永远从上面和左边两个位置来, 取最大值并加上当前位置的个数
        {
            if (i == 1 && j == 1)//1 1是起点, 跳过
                continue;
            if ((c[i][j - 1] < 0 && c[i - 1][j] < 0) || c[i][j] < 0) //位置不可达
                c[i][j] = -1;
            //位置可达
            else if (c[i][j - 1] >= 0 && c[i - 1][j] >= 0)
                v[i][j] = max(v[i - 1][j], v[i][j - 1]) + c[i][j];
            else if (c[i - 1][j] >= 0)
                v[i][j] = v[i - 1][j] + c[i][j];
            else
                v[i][j] = v[i][j - 1] + c[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << v[m][n] << endl;
    return 0;
}

/*
5 6
0  -1  0  1  0  0
1   0  0 -1  1  0
0   1  0 -1  1  0
0   0  0  1  0  1
-1 -1 -1  0  1  0
4
*/