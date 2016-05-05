#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    /*
    ������������:
    ��С��
    lower_bound(x)�ҵ���һ�����ڵ���x��λ��, ����С����λ��, �����������, �������ص�����, ���鷵��ָ��
    ������
    upper_bound(x)�ҵ���һ������x��λ��, ���������λ��, ������ǰ����, �������ص�����, ���鷵��ָ��
    */
    int a[6] = {10,50,100,150,200,250};
    vector<int> v(a, a + 6);
    v.push_back(700);
    v.push_back(900);
    v.push_back(1000);

    int *start = lower_bound(a, a + 6, 50);
    int *end = upper_bound(a, a + 6, 250);
    for (int *i = start; i != end; ++i)
        cout << *i << " ";
    cout << endl;

    vector<int>::iterator itlow = lower_bound(v.begin(), v.end(), 100);
    vector<int>::iterator itupp = upper_bound(v.begin(), v.end(), 900);
    for (vector<int>::iterator iter = itlow; iter != itupp; ++iter)
        cout << *iter << " ";
    cout << endl;

    set<int> s = {-10, -5, 2, 3, 4, 5, 7, 8, 10, 19, 30, 90};
    cout << "������ֵ���б�Χ�е�������" << endl;
    cout << "����Ϊ0�����" << *s.lower_bound(0) << endl;
    cout << "����Ϊ30���յ�" << *s.upper_bound(30) << endl;
    cout << endl;

    //������ҵ�Ԫ��û��������, ��ôupper_bound()���᷵��������end()������, lower_bound()����������begin()������
    cout << "\n����ֵ�����б����ֵ��������(1000):" << endl;
    cout << "��������Ϊ1000�ĵ�: ";
    set<int>::iterator sitlow = s.lower_bound(1000);
    if (sitlow == s.begin())
        cout << "�������޵�begin: " << cout << *(--sitlow) << endl;
    cout << endl;
    cout << "��������Ϊ1000�ĵ�: ";
    set<int>::iterator situpp = s.upper_bound(1000);
    if (sitlow == s.end())
        cout << "�������޵�end: " << *(--sitlow) << endl;
    cout << endl;




    cout << "\n����С���б���Сֵ��������(-1000):" << endl;
    sitlow = s.lower_bound(-1000);
    if (sitlow == s.begin())
        cout << "�������޵�begin: " << *sitlow << endl;

    situpp = s.upper_bound(-1000);
    if (sitlow == s.begin())
        cout << "���ҵ�����Ϊbegin: " << *sitlow << endl;

    return 0;
}