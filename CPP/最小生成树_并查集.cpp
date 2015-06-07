#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct edge
{
    int u, v, w;
    int operator< (edge a) const 
    {
        return w < a.w;
    } 
};

int find(int *p, int x)
{
    if (x == p[x])
        return p[x];
    else
        return p[x] = find(p, p[x]);
}

int main(int argc, char const *argv[])
{
    int n, m;//n个点,m条边
    cin >> n >> m;
    edge *edges = new edge[m];
    for (int i = 0; i < m; i++)//输入每条边两端的顶点和权重
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges, edges + m);
 
    int p[100];
    for (int i = 1; i <= n; i++)
        p[i] = i;

    int len = 0;
    for (int i = 0; i < m; i++)
    {
        int u = find(p, edges[i].u);
        int v = find(p, edges[i].v);
        if (u != v)
        {
            cout << "add edge " << ": " << edges[i].u << "-" << edges[i].v << " " << edges[i].w << endl;
            len += edges[i].w;
            p[v] = u;
        }
    }
    cout << len << endl;
    return 0;
}
/*
test data
7 12
1 2 2
1 3 3
2 4 6
2 5 5
2 3 4
3 4 3
3 6 7
4 5 4
4 6 8
5 6 2
5 7 4
6 7 3
*/