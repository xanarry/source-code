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

int min_v = 0x7FFFFFFF;
bool reachable = false;
int path[100];//记录到当前点遇到的最小容量
int dfs(int s, int t, int pre)
{
    if (s == t)
    {
        min_v = path[s];//如果到达汇点, 那么path[s]就是最小的容量限制, 单独保存
        reachable = true;
    }
    for (int v = 0; v <= ver; v++)
    {
        if (dist[v] == dist[s] + 1 && capacity[s][v] > 0)
        {
            path[v] = min(path[s], capacity[s][v]);//更新路径上的最小容量
            dfs(v, t, s);//搜索下一个结点
            if (reachable == true)//如果到达汇点, 终止搜索
                break;
        }
    }

    if (reachable)//递归返回时通过前面搜索的路径更新残余容量和反向边
    {
        capacity[pre][s] -= min_v;
        capacity[s][pre] += min_v;
    }
    else//如果搜索过程中到了一个不可到达汇点的点, 回退时, 应该复原min_v的值, 用户从当前起点搜索新的路径
        min_v = path[s];
}

int dinic(int s, int t)
{
    int maxflow = 0;
    while (bfs(s, t))
    {
        while (1)//一次bfs可能实现多次dfs
        {
            reachable = false;
            path[s] = 0x7FFFFFFF;
            dfs(s, t, s);
            if (reachable == false)
                break;
            maxflow += min_v;
        }
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

4 5
0 1 100
0 2 100
1 2 1
1 3 100
2 3 100
0 3
200

6 9
0 1 10
0 2 10
1 3 4
1 4 8
1 2 2
2 4 9
3 5 10
4 3 6
4 5 10
0 5
19

需要用到反向边的一个图
6 7
1 2 2
1 3 2
2 5 1
2 4 2
5 6 1
3 4 1
4 6 2
1 6
*/