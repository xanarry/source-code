/**********************************************************************
    文件描述: 测试treeMap
    命名约定: 所有变量和函数均使用驼峰式命名方式, 类的定义首字母大写
    完成时间: 2015-6-25
    最后修改: 2015-6-30
    auther: 熊洋(xanarry@163.com)
**********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "treeMap.hpp"
using namespace std;

typedef int Key;
typedef string Value;

void showEntrys(vector<Entry<Key, Value> > entrys)
{
    for (int i = 0; i < entrys.size(); i++)
        cout << entrys[i].key << " -> " << entrys[i].value << endl;
    cout << endl;
}

int main()
{
    
    TreeMap<Key, Value> tmap;
    vector<Entry<Key, Value> > entrys;

    int a[] =  {23, 2, 14, 20, 29, 11, 21, 27, 25, 9};  
    string str[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

    tmap.put(1, "one");
    entrys = tmap.entrySet();
    showEntrys(entrys);

    tmap.put(2, "two");
    entrys = tmap.entrySet();
    showEntrys(entrys);

    tmap.put(3, "three");
    entrys = tmap.entrySet();
    showEntrys(entrys);

    tmap.put(1, "oneeeee");
    entrys = tmap.entrySet();
    showEntrys(entrys);

    tmap.put(2, "twooooo");
    entrys = tmap.entrySet();
    showEntrys(entrys);

    tmap.put(3, "threeee");
    entrys = tmap.entrySet();
    showEntrys(entrys);

    tmap.put(4, "four");
    entrys = tmap.entrySet();
    showEntrys(entrys);


    cout << tmap.size() << endl;
    tmap.remove(1);
    entrys = tmap.entrySet();
    showEntrys(entrys);

    cout << tmap.size();
    tmap.remove(2);
    tmap.remove(3);
    entrys = tmap.entrySet();
    showEntrys(entrys);

    tmap.remove(4);
    entrys = tmap.entrySet();
    showEntrys(entrys);

    cout << tmap.size() << endl;

    tmap.put(100, "handrund");

//--------------------------------------------------------------------
    vector<Key> keyset = tmap.keySet();
    for (int i = 0; i < keyset.size(); i++)
        cout << keyset[i] << " ";
    cout << endl;

    vector<Value> values = tmap.values();
    for (int i = 0; i < values.size(); i++)
        cout << values[i] << " ";
    cout << endl;    
//-------------------------------------------------------------------

    return 0;
}
