#include <iostream>
#include <cstring>
#define INF 0x7FFFFFF
using namespace std;

int g[105][105];

void show_matrix(int m[][105], int d)
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
            g[i][j] = (i == j ? 0 : INF);
}

void floyd_warshell_shortest_path(int d)
{
    for (int k = 1; k <= d; k++)
        for (int i = 1; i <= d; i++)
            for (int j = 1; j <= d; j++)
                if (g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
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
        g[u][v] = w;
    }

    floyd_warshell_shortest_path(m);
    show_matrix(g, m);
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