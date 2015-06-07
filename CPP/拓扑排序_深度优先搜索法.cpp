#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, vector<string> > graph;//全局变量保存图
map<string, bool> visited;//标记节点是否访问
vector<string> topo_order;//保存拓扑排序结果

map<string, vector<string> > initialize()
{
    map<string, vector<string> > graph;//使用map建立名字到列表的映射
    string pname, adj;
    while (cin >> pname && pname != "0")//输入的顶点
    {
        visited[pname] = false;
        vector<string> adjs;
        graph[pname] = adjs;
        while (cin >> adj && adj != "0")//输入邻接顶点
            graph[pname].push_back(adj);
    }
    return graph;
}

void DFS(string start)//深度优先搜索
{
    for (vector<string>::iterator iter = graph[start].begin(); iter != graph[start].end(); ++iter)
    {   
        if (!visited[*iter])
        {
            visited[*iter] = true;
            DFS(*iter);
        }
    }
    //将深度优先搜索最底部的元素添加到vector的前端
    topo_order.insert(topo_order.begin(), start);
}   

void topo_sort(map<string, vector<string> > graph)
{
    for (map<string, bool>::iterator iter = visited.begin(); iter != visited.end(); ++iter)
    {
        if (!visited[iter->first])
        {
            visited[iter->first] = true;
            DFS(iter->first); //对每个节点没有访问过的节点进行深搜
        }
    }
}

int main(int argc, char const *argv[])
{
    graph = initialize();//输入图
    topo_sort(graph);//拓扑排序
    //输出拓扑排序结果
    for (int i = 0; i < topo_order.size(); i++)
        cout << topo_order[i] << " ";
    return 0;
    map<int, int> a;
}

/*测试数据 算法导论p336
undershorts
pants shoes 0
pants
shoes belt 0
belt
jacket 0
shirt
tie belt 0
tie
jacket 0
socks
shoes 0
watch
0
jacket
0
shoes
0
0
*/