#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <sstream>
#include <cstring>
using namespace std;

int adjacent_table[100][100];
int main(int argc, char const *argv[])
{
    cout << "依次输入顶点名称,输入\"0\"结束输入:" << endl;
    string pname;
    int pnum = 0;
    map<string, int> points;//使用map建立名字到下标的索引
    int maxn_len = -1;
    while (cin >> pname && pname != "0")//输入的顶点数
    {
        maxn_len = max(maxn_len, (int)pname.length());
        if (!points.count(pname))
            points[pname] = pnum++;
    }

    for (map<string, int>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        cout << "请输入\"" << iter->first << "\"的邻接顶点(0结束输入):" << endl;
        string adj;
        while (cin >> adj && adj != "0")
            adjacent_table[points[iter->first]][points[adj]] = 1;
    }

    stringstream format;
    format << "%" << maxn_len;//构造控制格式的字符串
    cout << "邻接矩阵如下:" << endl;
    printf((format.str() + "s ").c_str(), "\\");
    for (map<string, int>::iterator iter = points.begin(); iter != points.end(); ++iter)
        printf((format.str() + "s ").c_str(), iter->first.c_str());//输出标题栏
    cout << endl;
    //输出矩阵
    for (map<string, int>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        printf((format.str() + "s ").c_str(), iter->first.c_str());
        for (int j = 0; j < points.size(); j++)
            printf((format.str() + "d ").c_str(), adjacent_table[points[iter->first]][j]);
        cout << endl;
    }
    return 0;
}

/* 测试数据,三个顶点的单向环形图
v1 v2 v3 0
v2 0
v3 0
v1 0
*/