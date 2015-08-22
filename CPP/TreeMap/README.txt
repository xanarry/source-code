文件描述:
    "treeMap.h" 函数声明
    "treeMap.hpp" 函数定义
    "main.cpp" 测试功能的主函数

    其中Entry<type, type>是定义在treeMap.h中的一个结构体, 包含两个变量, 即key-value对

    代码 g++4.7.1 编译通过

功能描述:
    其功能为实现java语言中的treeMap

    使用treeMap<type, type>定义map

    假如有如下下定义:
    treeMap<int, string> map

    那么
    
    修改:
    map.put(Key key, Value value);插入键值对
    map.replace(Key key, Value oldValue, Value newValue);更新目标键值
    map.remove(Key key);删除键值对, 返回删除的结果
    map.clear();清空原来的树

    访问:
    map.get(Key);返回string, 通过键获取目标值
    map.firstKey();返回int, 找到最小的键
    map.lastKey();返回int, 找到最大的键
    map.firstEntry();返回Entry<Key, Value>, 找到键最小的键值对
    map.lastEntry();返回Entry<Key, Value>, 找到键最大的键值对
    map.vector<Key> keySet();返回vector<int>, 获取所有键
    map.values(); 返回vector<string>, 获取所有值;
    map.entrySet();返回vector<Entry<Key, Value>>, 获取所有键值对

    其他:
    map.size();返回int,获取插入的数据条数
    map.containsKey(key);返回bool, 判断目标键值是否存在
    map.output(); 先序遍历树, 测试使用
    