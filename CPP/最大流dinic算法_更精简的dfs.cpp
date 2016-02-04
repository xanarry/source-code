#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int capacity[100][100];//capacity
int dist[100];
int ver, edg;

int bfs(int s, int t)
{
    memset(dist, -1, sizeof(dist));
    queue<int> que;
    que.push(s);
    dist[s] = 0;
    //纯bfs, 权为1, 标记层次
    while (!que.empty() && que.front() != t)
    {
        int u = que.front();
        que.pop();
        for (int v = 0; v <= ver; v++)
        {
            if (u != v && dist[v] == -1 && capacity[u][v] > 0)
            {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }
    return dist[t] > 0;
}

int dfs(int s, int t, int min_v)
{
    if (s == t)//如果到达汇点, 返回最小容量
        return min_v;
    for (int i = 0; i <= ver; i++)
    {
        if (dist[i] == dist[s] + 1 && capacity[s][i] > 0)//邻接点满足层次要求并且有残余容量
        {
            //检查邻接点是否能够到达汇点, 能到达返回路径中的最小容量, 不能则返回0
            int temp = dfs(i, t, min(capacity[s][i], min_v));//min中为当前边的容量和上一条边的容量          
            if (temp > 0)//如果能到汇点
            {
                min_v = temp;//更新最容量, 添加temp防止走到了不可达汇点的点将min_v置为0后, 后续无法比较
                capacity[s][i] -= min_v;
                capacity[i][s] += min_v;
                return min_v;
            }
        }
    }
    return 0;
}


int dinic(int s, int t)
{
    int maxflow = 0, temp;
    while (bfs(s, t))
    {
        while ((temp = dfs(s, t, 0x7FFFFFFF)) > 0)
            maxflow += temp;//一次bfs可能实现多次dfs
    }
    return maxflow;
}   

int main(int argc, char const *argv[])
{
    int u, v, c, s, t;
    cin >> ver >> edg;
    for (int i = 0; i < edg; i++)
    {
        cin >> u >> v >> c;
        capacity[u][v] = c;
    }
    cin >> s >> t;
    cout << dinic(s, t) << endl;
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
*/