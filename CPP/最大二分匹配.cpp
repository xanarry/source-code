#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int capacity[100][100];
int parent[100];
int ver, edg;

/*最大二分匹配人文添加源点和汇点后与最大流一致, 唯一的区别是流的容量都是1, bfs中不需要记录最小容量, 恒为1*/
int bfs(int s, int t)
{
    queue<int> que;
    que.push(s);
    memset(parent, -1, sizeof(parent));
    while (!que.empty() && que.front() != t)
    {
        int u = que.front();
        que.pop();
        for (int v = 1; v <= ver + 5; v++)
        {
            if (v != u && parent[v] == -1 && capacity[u][v] == 1)
            {   
                parent[v] = u;
                que.push(v);//此处不需要更新最小容量, 恒为1
            }
        }
    }
    return parent[t] == -1 ? 0 : 1;
}

int bipartite_matching(int ver)
{
    //整个过程中容量恒为1
    int max_match = 0, u, v;
    while (bfs(0, ver + 1))
    {
        for (v = ver + 1; parent[v] != -1; v = parent[v])
        {
            int u = parent[v];
            capacity[u][v] -= 1;
            capacity[v][u] += 1;
        }
        max_match++;
    }
    return max_match;
}

int main(int argc, char const *argv[])
{
    int l, r;
    cin >> ver >> edg;
    for (int i = 0; i < edg; i++)
    {
        cin >> l >> r;
        capacity[l][r] = 1;
        capacity[0][l] = 1;//添加源点
        capacity[r][ver + 1] = 1;//添加汇点
    }
    cout << bipartite_matching(ver) << endl;
    return 0;
}

/*
graph from introduction to algorithm 2th edition p410
9 8
1 6
2 6
2 8
3 7
3 8
3 9
4 8
5 8
3
*/