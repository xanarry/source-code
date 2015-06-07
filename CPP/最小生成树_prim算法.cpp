#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Adj
{
    string name;
    int w;
    Adj(string np, int nw){name = np; w = nw;}
    Adj(){name = "nil"; w = 0xfffff;}
};

Adj min_w[1000];//保存每个点到生成树的最短距离
int p_count = 0;//顶点个数
map<string, vector<Adj> > graph;//保存图, 邻接表
map<string, int> index;//使用map建立string到int的映射,使之用字符串名字可以访问数组

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
    for (map<string, vector<Adj> >::iterator iter = graph.begin(); iter != graph.end(); ++iter)
    {
        index[iter->first] = p_count;
        min_w[p_count] = Adj(iter->first, 0xfffff);
        p_count++;
    }
}

string find_min()//找到距离最小的顶点
{
    string res;
    int temp = 0xfffff;
    for (map<string, int>::iterator iter = index.begin(); iter != index.end(); ++iter)
    {
        if (min_w[index[iter->first]].w != -1 && min_w[index[iter->first]].w < temp)
        {
            temp = min_w[index[iter->first]].w;
            res = iter->first;
        }
    }
    return res;
}

int prim()
{
    string parent = "NULL";
    int min_v = 0;
    for (int counter = 0; counter < p_count; counter++)
    {
        string start = find_min();//找到新顶点
        min_v += min_w[index[start]].w;//加上权值
        cout << "Meet:" << start << "\tAdd edge: " << parent << "-" << start << " w=" << min_w[index[start]].w << endl;
        parent = start;
        min_w[index[start]].w = -1;//使用过的顶点标记为-1
        vector<Adj> adjs = graph[start];//获取邻接顶点列表
        for (int i = 0; i < adjs.size(); i++)//更新新加入的顶点的邻接顶点到生成树的距离
            min_w[index[adjs[i].name]].w = min(min_w[index[adjs[i].name]].w, adjs[i].w);
    }
    cout << "min weight: " << min_v << endl;//输出最小权值
}

int main(int argc, char const *argv[])
{
    //输入可以接受字符串形式的顶点名字, 输入数据的形式为输入所有变的起点终点和权值
    init_graph();
    cout << "input root:";
    string start;
    cin >> start;
    min_w[index[start]].w = 0; //初始化第一个起点
    int min_w = prim();
    return 0;
}

/*测试数据 教课书p218 图7.3
1 2 16
2 3 5
3 4 6
2 4 6
5 4 18
1 5 19
1 6 21
5 6 33
2 6 11
4 6 14
0
1
*/