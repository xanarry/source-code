#include <iostream>
#include <algorithm>
using namespace std;

int p[1000], m[100][100], pos[100][100];

void print_order(int i, int j)
{
    if (i == j)
        cout << i;
    else
    {
        cout << "(";
        print_order(i, pos[i][j] - 1);
        print_order(pos[i][j], j);
        cout << ")";
    }
}

int main(int argc, char const *argv[])
{
    int n, r, c, cnt = 0, j;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r >> c;
        if (i == 0)
        {
            p[cnt++] = r;
            p[cnt++] = c;
        }
        else
            p[cnt++] = c;
        m[i][i] = 0;
    }

    for (int l = 1; l < n; l++)
    {
        for (int i = 0; i < n - l; i++)
        {
            j = i + l;
            m[i][j] = 0x7FFFFFF;
            for (int k = i; k < j; k++)
            {
                int tmp = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (tmp < m[i][j])
                {
                    m[i][j] = tmp;
                    pos[i][j] = k + 1;
                }
            }
        }
    }

    cout << m[0][n - 1] << endl;
    print_order(0, n - 1);
    return 0;
}

/*
3
2 3
3 4
4 5

6
30 35
35 15
15 5
5 10
10 20
20 25
*/