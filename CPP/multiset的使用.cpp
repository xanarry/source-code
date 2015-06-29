#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    multiset<string> mset;
    //insert
    mset.insert("z");
    mset.insert("s");
    mset.insert("x");
    mset.insert("t");
    mset.insert("t");
    mset.insert("t");
    mset.insert("c");
    mset.insert("j");
    mset.insert("c");
    mset.insert("a");

    //输出multset中的所有元素,可以重复的
    for (multiset<string, string>::iterator iter = mset.begin(); iter != mset.end(); ++iter)
        cout << *iter << endl;
    cout << "-------------------" << endl;

    //输出每个值的所有元素, equal_range()返回一对包含所有元素的迭代器的pair对象
    string keys[] = {"c", "t", "s", "z"};
    for (auto key : keys)
    {
        cout << key << " => ";
        pair<multiset<string, string>::iterator, multiset<string, string>::iterator> range;
        range = mset.equal_range(key);
        for (multiset<string, string>::iterator inner_iter = range.first; inner_iter != range.second; ++inner_iter)
            cout << *inner_iter << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;

    //输出key对应的元素个数
    cout << mset.count("t") << endl;
    //返回key为"t"的键值对
    cout << *mset.find("t") << endl;
    cout << "----------------------" << endl;

    //获取key为"x"的上限迭代器
    multiset<string, string>::iterator itupp = mset.upper_bound("x");
    //获取key为"t"的下限迭代器
    multiset<string, string>::iterator itlow = mset.lower_bound("t");
    //输出从't'到'x'的所有元素
    for (multiset<string, string>::iterator iter = itlow; iter != itupp; ++iter)
        cout << *iter << endl;
    cout << "-----------------------" << endl;

    //同find()函数一样, 如果存在多个键, 删除第一个
    mset.erase(mset.find("c"));

    //如果要删除某个键的所有内容, 则将equal_range()返回迭代器对的first作为起点, second作为终点
    mset.erase(mset.equal_range("t").first, mset.equal_range("t").second);

    for (multiset<string, string>::iterator iter = mset.begin(); iter != mset.end(); ++iter)
        cout << *iter << endl;
    cout << "-------------------" << endl;

    //可以使用swap()函数交换两个multiset, 两个multiset的大小不必一致
    /*  假如a = multiset_1
            b = multiset_2
        使用a.swap(b)后
        a的内容变成multiset_2的
        b的内容变成multiset_1的
    */
    return 0;
}