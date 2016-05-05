#include <iostream>
#include <cstring>
#define INF 0x7FFFFFF
using namespace std;

int init[100][100];
int pre[100][100];
int temp[100][100];

void show_matrix(int m[][100], int d)
{  
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            if (m[i][j] == INF)
                cout << "X ";
            else
                cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void init_matrix(int d)
{
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= d; j++)
            init[i][j] = (i == j ? 0 : INF);
}

void floyd_warshell_shortest_path(int d)
{
    //k表示经过k个顶点i到j的最短路径,k在最前面是因为在经过多个顶点构成最短路径时, 必须建立在之前经过k-1个顶点的最短路径已经得出
    for (int k = 1; k <= d; k++)
        for (int i = 1; i <= d; i++)
            for (int j = 1; j <= d; j++)
                if (pre[i][j] > pre[i][k] + pre[k][j])
                    pre[i][j] = pre[i][k] + pre[k][j];
}

int main(int argc, char const *argv[])
{
    int m, n, u, v, w;
    cin >> m >> n;//vertex, edge
    init_matrix(m);
    while (n--)
    {
        cin >> u >> v >> w;
        if (u == v)
            w = 0;
        init[u][v] = w;
        pre[u][v] = w;
    }
    cout << "default matrix" << endl;
    show_matrix(init, m);
    memcpy(pre, init, sizeof(init));

    floyd_warshell_shortest_path(m);
    cout << "shortest paths" << endl;
    show_matrix(pre, m);
    return 0;
}

/*
introduction to algorithm 2th edition, pic 25-1 p384
5 9
1 2 3
1 3 8
1 5 -4
2 4 1
2 5 7
3 2 4
4 3 -5
4 1 2
5 4 6

introduction to algorithm 2th edition, pic 24-2 p360
5 10
1 2 3
1 4 5
2 3 6
2 4 2
3 5 2
4 2 1
4 3 4
4 5 6
5 1 3
5 3 7
*/