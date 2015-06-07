#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "依次输入顶点名称,输入\"0\"结束输入:" << endl;
    map<string, vector<string> > points;//使用map建立名字到列表的映射
    string pname, adj;
    while (cin >> pname && pname != "0")//输入的顶点
    {
        cout << "请输入\"" << pname << "\"的邻接顶点(0结束输入):" << endl;
        while (cin >> adj && adj != "0")
            points[pname].push_back(adj);
    }

    cout << "邻接表如下:" << endl;
    for (map<string, vector<string> >::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        cout << iter->first << ": ";
        for (int i = 0; i < iter->second.size(); i++)
            cout << (iter->second)[i] << " ";
        cout << endl;
    }
    return 0;
}

/* 测试数据,三个顶点的单向环形图
v1
v2 0
v2
v3 0
v3
v1 0
0
*/