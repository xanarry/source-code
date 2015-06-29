#include <iostream>
#include <string>
#include <vector>
#include "treeMap.hpp"
using namespace std;

typedef int Key;
typedef string Value;

void display(vector<Entry<Key, Value> > entrys)
{
    for (int i = 0; i < entrys.size(); i++)
        cout << entrys[i].key << " -> " << entrys[i].value << endl;
    cout << endl;
}

int main()
{
    TreeMap<Key, Value> tmap;

    int a[] =  {23, 2, 14, 20, 29, 11, 21, 27, 25, 9};  
    string str[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    tmap.put(1, "one");
    display(tmap.entrySet());
    tmap.put(2, "two");
    display(tmap.entrySet());
    tmap.put(3, "three");
    display(tmap.entrySet());
    tmap.put(1, "oneeeee");
    display(tmap.entrySet());
    tmap.put(2, "twooooo");
    display(tmap.entrySet());
    tmap.put(3, "threeee");
    display(tmap.entrySet());
    tmap.put(4, "four");
    display(tmap.entrySet());

    cout << tmap.size() << endl;
    tmap.remove(1);
    display(tmap.entrySet());
    cout << tmap.size();
    tmap.remove(2);
    tmap.remove(3);
    display(tmap.entrySet());
    tmap.remove(4);
    display(tmap.entrySet());
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

    vector<Entry<Key, Value> > entry = tmap.entrySet();
    
    for (int i = 0; i < entry.size(); i++)
        cout << entry[i].key << " -> " << entry[i].value << endl;
    cout << endl;
//-------------------------------------------------------------------

    return 0;
}
