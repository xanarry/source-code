#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "�������붥������,����\"0\"��������:" << endl;
    map<string, vector<string> > points;//ʹ��map�������ֵ��б��ӳ��
    string pname, adj;
    while (cin >> pname && pname != "0")//����Ķ���
    {
        cout << "������\"" << pname << "\"���ڽӶ���(0��������):" << endl;
        while (cin >> adj && adj != "0")
            points[pname].push_back(adj);
    }

    cout << "�ڽӱ�����:" << endl;
    for (map<string, vector<string> >::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        cout << iter->first << ": ";
        for (int i = 0; i < iter->second.size(); i++)
            cout << (iter->second)[i] << " ";
        cout << endl;
    }
    return 0;
}

/* ��������,��������ĵ�����ͼ
v1
v2 0
v2
v3 0
v3
v1 0
0
*/