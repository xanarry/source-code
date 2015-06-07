#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, vector<string> > graph;//ȫ�ֱ�������ͼ
map<string, bool> visited;//��ǽڵ��Ƿ����
vector<string> topo_order;//��������������

map<string, vector<string> > initialize()
{
    map<string, vector<string> > graph;//ʹ��map�������ֵ��б��ӳ��
    string pname, adj;
    while (cin >> pname && pname != "0")//����Ķ���
    {
        visited[pname] = false;
        vector<string> adjs;
        graph[pname] = adjs;
        while (cin >> adj && adj != "0")//�����ڽӶ���
            graph[pname].push_back(adj);
    }
    return graph;
}

void DFS(string start)//�����������
{
    for (vector<string>::iterator iter = graph[start].begin(); iter != graph[start].end(); ++iter)
    {   
        if (!visited[*iter])
        {
            visited[*iter] = true;
            DFS(*iter);
        }
    }
    //���������������ײ���Ԫ����ӵ�vector��ǰ��
    topo_order.insert(topo_order.begin(), start);
}   

void topo_sort(map<string, vector<string> > graph)
{
    for (map<string, bool>::iterator iter = visited.begin(); iter != visited.end(); ++iter)
    {
        if (!visited[iter->first])
        {
            visited[iter->first] = true;
            DFS(iter->first); //��ÿ���ڵ�û�з��ʹ��Ľڵ��������
        }
    }
}

int main(int argc, char const *argv[])
{
    graph = initialize();//����ͼ
    topo_sort(graph);//��������
    //�������������
    for (int i = 0; i < topo_order.size(); i++)
        cout << topo_order[i] << " ";
    return 0;
    map<int, int> a;
}

/*�������� �㷨����p336
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