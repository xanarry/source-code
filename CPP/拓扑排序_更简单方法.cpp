#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int a[100];//保存每个顶点的入度，数组的下标表示顶点1-n，数组的值表示该编号顶点的入度

int main(int argc, char const *argv[])
{
    int n, m, k, pn,t;
    map<int, vector<int> > points;//保存一个顶点的编号和该顶点的邻接顶点
    cin >> n;//输入顶点数
    for (int i = 0; i < n; i++)
    {
        cin >> pn >> m;//输入点编号，邻接顶点数
        vector<int> adjs;
        for (int j = 0; j < m; j++)
        {
            cin >> t;
            adjs.push_back(t);//输入该点的所有邻接顶点，使用vector保存
        }
        points[pn] = adjs;
    }
    
    //计算每个顶点的入度数量
    for (map<int, vector<int> >::iterator iter = points.begin(); iter != points.end(); ++iter)
        for (int i = 0; i < points[iter->first].size(); i++)
            a[points[iter->first][i]]++;
    
    queue<int> order;//一次将入度为空的节点插入队列
    for (int i = 1; i <= n; i++)//首先插入本来就入度就为空的顶点
        if (a[i] == 0)
            order.push(i);

    int mk = 0;
    while (mk < n)//当为对所有顶点完成排序时，不能停止排序
    {
        int temp = order.front();//当前入度为0的元素出队
        cout << temp << " ";
        order.pop();
        for (int i = 0; i < points[temp].size(); i++)
        {
            a[points[temp][i]]--;//重新设置该点邻接顶点的入度
            if (a[points[temp][i]] == 0)//将入度为0的顶点插入队列
                order.push(points[temp][i]);
        }
        mk++;
    }
    return 0;
}
/*
9
1 3 3 4 5
2 2 4 5
3 2 6 7
4 5 3 6 7 8 5
5 2 7 8
6 1 7
7 1 9
8 1 7
9 0

re = 1 2 4 3 5 6 8 7 9
*/
