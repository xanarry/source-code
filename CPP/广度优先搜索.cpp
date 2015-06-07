//广度优先搜索
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

int path_depth[100];

void bfs(int start, map<int, vector<int> > points)
{
    memset(path_depth, -1, sizeof(path_depth));
    queue<int> que;
    que.push(start);
    int depth = 0;
    path_depth[start] = depth;
    while (!que.empty())
    {
        start = que.front(); que.pop();
        vector<int> adjs = points[start];
        depth = path_depth[start] + 1;
        for (int i = 0; i < adjs.size(); i++)
        {
            if (path_depth[adjs[i]] == -1)
            {
                path_depth[adjs[i]] = depth;
                que.push(adjs[i]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m, k, pn, ad, start;
    map<int, vector<int> > points;//保存一个顶点的编号和该顶点的邻接顶点
    cin >> n;//输入顶点数
    for (int i = 0; i < n; i++)
    {
        cin >> pn >> m;//输入点编号，邻接顶点数
        vector<int> adjs;
        for (int j = 0; j < m; j++)//输入邻接顶点
        {
            cin >> ad;
            adjs.push_back(ad);//输入该点的所有邻接顶点，使用vector保存
        }
        points[pn] = adjs;
    }
    cin >> start;//输入搜索起点
    bfs(start, points);
    for (int i = 1; i <= n; i++)
        cout << "from" <<  start << " to " << i << " 's len: " << path_depth[i] << endl;
    return 0;
}

/*
6
1 2 2 3
2 3 1 3 4
3 4 1 2 4 5
4 4 2 3 5 6
5 3 3 5 6
6 2 4 5
3
*/