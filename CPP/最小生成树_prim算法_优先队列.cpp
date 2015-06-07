#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct Adj
{
    string name;
    int w;
    Adj(string np, int nw){name = np; w = nw;}
    Adj(){name = "nil"; w = 0xfffff;}
    bool operator< (const Adj a) const
    {
        return w > a.w;
    }
};

map<string, vector<Adj> > graph;//保存图, 邻接表

void init_graph()
{  
    string u, v;
    int w;
    cout << "input u, v and w, \"0\" end up" << endl;
    while (cin >> u && u != "0" && cin >> v >> w)
    {
        vector<int> adjacent;
        graph[u].push_back(Adj(v, w));
        graph[v].push_back(Adj(u, w));
    }
}

int prim()
{
    priority_queue<Adj> pque;
    set<string> added;
    string start, pre;
    int min_v = 0;

    cout << "input root:";
    cin >> start;

    pre = start;
    pque.push(Adj(start, 0));
    added.insert(start);
    while (added.size() < graph.size() && !pque.empty())
    {
        Adj temp = pque.top();
        pque.pop();
        if (!added.count(temp.name))
        {
            cout << "Meet: " << temp.name << "\tadd edge: " << pre << "-" << temp.name << " w=" << temp.w << endl; 
            added.insert(temp.name);
            min_v += temp.w;
            pre = temp.name;
        }

        vector<Adj> adjacent = graph[temp.name];
        for (int i = 0; i < adjacent.size(); i++)
            if (!added.count(adjacent[i].name))
                pque.push(Adj(adjacent[i].name, adjacent[i].w));
    }
    cout << "min weight: " << min_v << endl;//输出最小权值
}

int main(int argc, char const *argv[])
{
    //输入可以接受字符串形式的顶点名字, 输入数据的形式为输入所有变的起点终点和权值
    init_graph();
    prim();
    return 0;
}

/*测试数据 教课书p218 图7.3
a b 4
b c 8
a h 8
b h 11
c i 2
h i 7
g i 6
g h 1
g f 2
c f 4
c d 7
d e 9
d f 14
f e 9
0
a

*/