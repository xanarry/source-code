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
                cout << "N ";
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
    {
        for (int j = 1; j <= d; j++)
        {
            if (i == j)
                init[i][j] = 0;
            else
                init[i][j] = INF;
        }
    }
}

void extend_shortest_path(int d)
{
    memcpy(temp, pre, sizeof(init));
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= d; j++)
            for (int k = 1; k <= d; k++)
                if (temp[i][k] < INF && init[k][j] < INF && temp[i][k] + init[k][j] < pre[i][j])
                    pre[i][j] = temp[i][k] + init[k][j];
}

void all_pair_shortest_paths(int d)
{
    for (int i = 1; i < d; i++)
        extend_shortest_path(d);
}

int main(int argc, char const *argv[])
{
    int m, n, u, v, w;
    cin >> m >> n;//vertex, edge
    init_matrix(m);
    while (n--)
    {
        cin >> u >> v >> w;
        init[u][v] = w;
        pre[u][v] = w;
    }
    cout << "default matrix" << endl;
    show_matrix(init, m);
    memcpy(pre, init, sizeof(init));

    all_pair_shortest_paths(m);
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