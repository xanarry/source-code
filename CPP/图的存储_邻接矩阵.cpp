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
    cout << "�������붥������,����\"0\"��������:" << endl;
    string pname;
    int pnum = 0;
    map<string, int> points;//ʹ��map�������ֵ��±������
    int maxn_len = -1;
    while (cin >> pname && pname != "0")//����Ķ�����
    {
        maxn_len = max(maxn_len, (int)pname.length());
        if (!points.count(pname))
            points[pname] = pnum++;
    }

    for (map<string, int>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        cout << "������\"" << iter->first << "\"���ڽӶ���(0��������):" << endl;
        string adj;
        while (cin >> adj && adj != "0")
            adjacent_table[points[iter->first]][points[adj]] = 1;
    }

    stringstream format;
    format << "%" << maxn_len;//������Ƹ�ʽ���ַ���
    cout << "�ڽӾ�������:" << endl;
    printf((format.str() + "s ").c_str(), "\\");
    for (map<string, int>::iterator iter = points.begin(); iter != points.end(); ++iter)
        printf((format.str() + "s ").c_str(), iter->first.c_str());//���������
    cout << endl;
    //�������
    for (map<string, int>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        printf((format.str() + "s ").c_str(), iter->first.c_str());
        for (int j = 0; j < points.size(); j++)
            printf((format.str() + "d ").c_str(), adjacent_table[points[iter->first]][j]);
        cout << endl;
    }
    return 0;
}

/* ��������,��������ĵ�����ͼ
v1 v2 v3 0
v2 0
v3 0
v1 0
*/