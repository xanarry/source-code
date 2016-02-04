#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int capacity[100][100];//capacity
int parent[100];
vector<int> g[100];//graph, adjacent table

int bfs(int s, int t)
{
    memset(parent, -1, sizeof(parent));
    int min_v = 0x7fffffff;
    queue<int> que;
    que.push(s);
    while (!que.empty())
    {
        int u = que.front(); que.pop();
        for (int i = 0; i < g[u].size(); i++)//adjacent vertex
        {
            int v = g[u][i];
            if (parent[v] == -1 && capacity[u][v] > 0)
            {
                que.push(v);
                parent[v] = u;
                min_v = min(min_v, capacity[u][v]);
            }
        }
    }
    return parent[t] == -1 ? 0 : min_v;
}

int edmonds_karp(int s, int t)
{
    int max_flow = 0, u, v;
    while (1)//不断增广路径, 直到无法继续增广, 流最大
    {
        int min_v = bfs(s, t);
        if (min_v == 0)
            break;

        for (v = t; parent[v] != -1; v = parent[v])
        {
            u = parent[v];
            capacity[u][v] -= min_v;
            capacity[v][u] += min_v;
        }
        max_flow += min_v;
    }
    return max_flow;
}

int main(int argc, char const *argv[])
{
    int ver, edg, u, v, c, s, t;
    cin >> ver >> edg;
    for (int i = 0; i < edg; i++)
    {
        cin >> u >> v >> c;
        g[u].push_back(v);
        capacity[u][v] = c;
    }
    cin >> s >> t;
    cout << edmonds_karp(s, t) << endl;
    return 0;
}
/*
6 10
0 1 16
0 2 13
1 3 12
1 2 10
2 1 4
2 4 14
3 5 20
3 2 9
4 3 7
4 5 4
0 5
23

4 5
0 1 100
0 2 100
1 2 1
1 3 100
2 3 100
0 3
200
*/