#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, vector<string> > input_graph()
{
    cout << "input each point respectively, input 0 to end up"  << endl;
    map<string, vector<string> > graph;//使用map建立名字到列表的映射
    string pname, adj;
    while (cin >> pname && pname != "0")//输入的顶点
    {
        cout << "input " << pname << "'s adjacents, end with 0" << endl;
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

int main(int argc, char const *argv[])
{
    map<string, vector<string> > graph = input_graph();
    display_graph(graph);
    map<string, vector<string> > trans_graph = trans(graph);
    display_graph(trans_graph);   
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