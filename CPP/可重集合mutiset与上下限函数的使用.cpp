#include <iostream>
#include <set>
using namespace std;
int main ()
{
    multiset<int> mymultiset;
    multiset<int>::iterator itlow, itup;
    mymultiset.insert(1);
    mymultiset.insert(1);
    mymultiset.insert(2);
    mymultiset.insert(2);
    mymultiset.insert(2);
    mymultiset.insert(3);
    mymultiset.insert(4);
    mymultiset.insert(5);
    mymultiset.insert(9);
    mymultiset.insert(10);
    cout << "all member: ";
    for (multiset<int>::iterator it = mymultiset.begin(); it != mymultiset.end(); ++it)
        cout << ' ' << * it;
    cout << '\n';


    cout << "lower bound to end:" << endl;
    //下限会右移动指针
    itlow = mymultiset.lower_bound(7);//返回下限迭代器, 即大于等于val的起点迭代器

    for (multiset<int>::iterator it = itlow; it != mymultiset.end(); ++it)
        cout << * it << " ";
    cout << '\n';


    cout << "begin to upper bound:" << endl;
    //上限会向左移动指针
    itup = mymultiset.upper_bound(7);//返回上限迭代器, 即小于等于val的终点迭代器
    for (multiset<int>::iterator it = mymultiset.begin(); it != itup; ++it)
        cout << *it << " ";
    cout << '\n';
    return 0;
}