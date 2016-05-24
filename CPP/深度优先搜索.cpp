#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool visited[100] = {false};
map<int, vector<int> > points;//保存一个顶点的编号和该顶点的邻接顶点

void dfs(int start)
{
    if (!visited[start])
    {
        visited[start] = true;
        for (int i = 0; i < points[start].size(); i++)
            dfs(points[start][i]);
    }
}

int main(int argc, char const *argv[])
{
    int n, m, k, pn, ad, start;
    cin >> n;//输入顶点数
    for (int i = 0; i < n; i++)
    {
        cin >> pn >> m;//输入点编号，邻接顶点数
        for (int j = 0; j < m; j++)//输入邻接顶点
        {
            cin >> ad;
            points[pn].push_back(ad);//输入该点出度所指向的邻接顶点,因为深搜是有向的,使用vector保存
        }
    }
    for (map<int, vector<int> >::iterator iter = points.begin(); iter != points.end(); ++iter)
        dfs(iter->first);
    
    for (int i = 1; i <= n; i++)
        cout << visited[i] << endl;
    return 0;
}

/*测试数据
6
1 2 2 3
2 2 4 5
3 2 2 5
4 2 5 6
5 1 6
6 0

search result:
*/