#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    multimap<string, string> mmap;
    //insert
    mmap.insert(make_pair("z", "123456"));
    mmap.insert(make_pair("s", "78557878"));
    mmap.insert(make_pair("x", "78557878"));
    mmap.insert(make_pair("t", "911567"));
    mmap.insert(make_pair("t", "xanarry@gmail.com"));
    mmap.insert(make_pair("t", "76y23578"));
    mmap.insert(make_pair("c", "635478"));
    mmap.insert(make_pair("j", "65sfd78"));
    mmap.insert(make_pair("c", "7685578"));
    mmap.insert(make_pair("a", "9765578"));

    //输出multmap中的所有元素,可以重复的
    for (multimap<string, string>::iterator iter = mmap.begin(); iter != mmap.end(); ++iter)
        cout << iter->first << " " << iter->second << endl;
    cout << "-------------------" << endl;

    //输出每个key对应的所有的value: equal_range("key"), 返回一对包含所有value的迭代器的pair对象
    string keys[] = {"c", "t", "s", "z"};
    for (auto key : keys)
    {
        cout << key << " => ";
        pair<multimap<string, string>::iterator, multimap<string, string>::iterator> range;
        range = mmap.equal_range(key);
        for (multimap<string, string>::iterator inner_iter = range.first; inner_iter != range.second; ++inner_iter)
            cout << inner_iter->second << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;

    //输出key对应的元素个数
    cout << mmap.count("t") << endl;
    //返回key为"t"的键值对
    cout << mmap.find("t")->second << endl;
    cout << "----------------------" << endl;

    //获取key为"x"的上限迭代器
    multimap<string, string>::iterator itupp = mmap.upper_bound("x");
    //获取key为"t"的下限迭代器
    multimap<string, string>::iterator itlow = mmap.lower_bound("t");
    //输出从't'到'x'的所有元素
    for (multimap<string, string>::iterator iter = itlow; iter != itupp; ++iter)
        cout << iter->first << " " << iter->second << endl;
    cout << "-----------------------" << endl;

    //同find()函数一样, 如果存在多个键, 删除第一个
    mmap.erase(mmap.find("c"));

    //如果要删除某个键的所有内容, 则将equal_range()返回迭代器对的first作为起点, second作为终点
    mmap.erase(mmap.equal_range("t").first, mmap.equal_range("t").second);

    for (multimap<string, string>::iterator iter = mmap.begin(); iter != mmap.end(); ++iter)
        cout << iter->first << " " << iter->second << endl;
    cout << "-------------------" << endl;

    //可以使用swap()函数交换两个multimap, 两个multimap的大小不必一致
    /*  假如a = multimap_1
            b = multimap_2
        使用a.swap(b)后
        a的内容变成multimap_2的
        b的内容变成multimap_1的
    */
    return 0;
}