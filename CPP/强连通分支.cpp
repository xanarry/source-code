#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct LASTVT
{
    string name;
    int visit_time;
    bool operator< (LASTVT a) const
    {
        return visit_time < a.visit_time;
    }
};

map<string, vector<string> > trans_graph;
map<string, bool> visited;
priority_queue<LASTVT> last_searched;
int search_time = 0;

map<string, vector<string> > initialize()
{
    map<string, vector<string> > graph;//使用map建立名字到列表的映射
    string pname, adj;
    while (cin >> pname && pname != "0")//输入的顶点
    {
        visited[pname] = false;
        vector<string> adjs;
        graph[pname] = adjs;
        while (cin >> adj && adj != "0")
            graph[pname].push_back(adj);
    }
    return graph;
}

map<string, vector<string> > trans(map<string, vector<string> > graph)
{
    map<string, vector<string> > trans_graph;
    for (map<string, vector<string> >::iterator iter = graph.begin(); iter != graph.end(); ++iter)
        for (int i = 0; i < iter->second.size(); i++)
            trans_graph[iter->second[i]].push_back(iter->first);
    return trans_graph;
}

void display_graph(map<string, vector<string> > graph)
{
    cout << "graph as follow:" << endl;
    for (map<string, vector<string> >::iterator iter = graph.begin(); iter != graph.end(); ++iter)
    {
        cout << iter->first << ": ";
        for (int i = 0; i < iter->second.size(); i++)
            cout << (iter->second)[i] << " ";
        cout << endl;
    }
}

void DFS(map<string, vector<string> > graph, string start, int order)
{
    if (order == 2)
        cout << start << " ";

    for (vector<string>::iterator iter = graph[start].begin(); iter != graph[start].end(); ++iter)
    {   
        if (!visited[*iter])
        {
            visited[*iter] = true;
            DFS(graph, *iter, order);
        }
    }

    if (order == 1)
    {
        search_time++;
        LASTVT lasv;
        lasv.name = start;
        lasv.visit_time = search_time;
        last_searched.push(lasv);
    }
}   

void SCC(map<string, vector<string> > graph)
{
    for (map<string, bool>::iterator iter = visited.begin(); iter != visited.end(); ++iter)
        iter->second = false;

    while (!last_searched.empty())
    {
        LASTVT t = last_searched.top(); 
        last_searched.pop();
        if (!visited[t.name])
        {
            cout << "SCC root of: " << t.name << " -> [";
            visited[t.name] = true;
            DFS(graph, t.name, 2);
            cout << "\b]" << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    map<string, vector<string> > graph = initialize();
    map<string, vector<string> > trans_graph = trans(graph);

    for (map<string, bool>::iterator iter = visited.begin(); iter != visited.end(); ++iter)
    {
        if (!visited[iter->first])
        {
            visited[iter->first] = true;
            DFS(graph, iter->first, 1); 
        }
    }

    SCC(trans_graph);
    return 0;
}

/*测试数据 算法导论p338
a
b 0
b
c f e 0
c
d g 0
d
c h 0
e
a f 0
f
g 0
g
f h 0
h 
0
0
*/