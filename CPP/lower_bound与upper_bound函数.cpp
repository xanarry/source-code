#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    /*
    在有序序列中:
    不小于
    lower_bound(x)找到第一个大于等于x的位置, 即最小下限位置, 可以向后延伸, 容器返回迭代器, 数组返回指针
    更大于
    upper_bound(x)找到第一个大于x的位置, 即最大上限位置, 可以向前延伸, 容器返回迭代器, 数组返回指针
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
    cout << "查找数值在列表范围中的上下限" << endl;
    cout << "下限为0的起点" << *s.lower_bound(0) << endl;
    cout << "上限为30的终点" << *s.upper_bound(30) << endl;
    cout << endl;

    //如果查找的元素没有序列中, 那么upper_bound()将会返回容器的end()迭代器, lower_bound()返回容器的begin()迭代器
    cout << "\n查找值大于列表最大值的上下限(1000):" << endl;
    cout << "查找下限为1000的点: ";
    set<int>::iterator sitlow = s.lower_bound(1000);
    if (sitlow == s.begin())
        cout << "查找下限到begin: " << cout << *(--sitlow) << endl;
    cout << endl;
    cout << "查找上限为1000的点: ";
    set<int>::iterator situpp = s.upper_bound(1000);
    if (sitlow == s.end())
        cout << "查找上限到end: " << *(--sitlow) << endl;
    cout << endl;




    cout << "\n查找小于列表最小值的上下限(-1000):" << endl;
    sitlow = s.lower_bound(-1000);
    if (sitlow == s.begin())
        cout << "查找下限到begin: " << *sitlow << endl;

    situpp = s.upper_bound(-1000);
    if (sitlow == s.begin())
        cout << "查找到上限为begin: " << *sitlow << endl;

    return 0;
}