#include <iostream>
#include <vector>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 100;

vector<int> g[MAXN + 1];//graph adjacet table
map<int, int> que;//模拟队列
int w[MAXN + 1][MAXN + 1], len[MAXN + 1], n, m;

pair<int, int> findMin()
{
    pair<int, int> tmp = make_pair(1, INF);
    for (map<int, int>::iterator i = que.begin(); i != que.end(); ++i)
        if (i->second < tmp.second)
            tmp = *i;
    return tmp;
}

void dijkstra(int start)
{
    for (int i = 1; i <= n; i++)
        len[i] = que[i] = INF;
    len[start] = que[start] = 0;
    while (!que.empty())
    {
        pair<int, int> cur = findMin();
        int u = cur.first;
        que.erase(u);
        for (int i = 0; i < g[u].size(); i++) //all adjacent point
            if (len[u] + w[u][g[u][i]] < len[g[u][i]])//upate len
                que[g[u][i]] = len[g[u][i]] = len[u] + w[u][g[u][i]];
    }
}

int main(int argc, char const *argv[])
{
    int a, b, c, s;
    cin >> n >> m;//点, 边
    for (int i = 0; i < m; i++)//每条边起点->终点->权
    {
        cin >> a >> b >> c;
        g[a].push_back(b);
        w[a][b] = c;
    }
    cin >> s;
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        cout << "to: " << i << " len:" << len[i] << endl;
    return 0;
}

/*
introduction to algorithm 2th edition p367
5 10
1 2 10
1 5 5
2 3 1
2 5 2
3 4 4
4 3 6
4 1 7
5 2 3
5 3 9
5 4 2
3

3 3
1 3 1
3 1 2
3 2 5
3
*/