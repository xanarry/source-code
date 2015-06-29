/**********************************************************************
    文件描述: 声明treemap的基本结构和基本函数定义
    命名约定: 所有变量和函数均使用驼峰式命名方式, 类的定义首字母大写
    完成时间: 2015-6-25
**********************************************************************/
#ifndef TREEMAP_H_INCLUDED
#define TREEMAP_H_INCLUDED
#include <vector>

template<typename Key, typename Value>
/************************************
    保存键值对数据
************************************/
struct Entry
{
    Key key;
    Value value; 
    Entry(Key k, Value v){key = k; value = v;}
    Entry(){}
};

/*********************************************************************
    treemap类, 使用红黑树实现, 其中树中的每个节点使用嵌套节点类
*********************************************************************/
template<typename Key, typename Value> 
class TreeMap
{
private:

    //枚举类型标记节点的颜色为红色或者为黑色
    enum {BLACK = 0, RED = 1};

    /*********************************************
        嵌套类, 保存每个二叉树中每个节点的数据
        其所有属性对于外部类都是可访问修改的
    *********************************************/
    class TreeNode
    {
    public:
        Entry<Key, Value> entry;//保存键值对
        bool color;//节点颜色
        TreeNode *left;//左子树指针
        TreeNode *right;//右子树指针
        TreeNode *parent;//节点颜色
        TreeNode(){}
        ~TreeNode(){}
    };

    TreeNode *rbt;//树根节点, 初始化还没有插入任何数据时rbt==nil
    TreeNode *nil;//标记NULL的节点, 其颜色为BLACK, left, right, parent指针均指向自己

    long nodeCount;//树种节点的的个数

    std::vector<Key> KeySet;//保存所有key
    std::vector<Value> Values;//保存所有value
    std::vector<Entry<Key, Value> > EntrySet;//保存所有键值对

    //初始化nil节点
    TreeNode *getNil();

    //插入数据数据时生成新的节点
    TreeNode *newNode(TreeNode *parent, Key key, Value value);

    //所有目标节点是否存在, 返回节点指针
    TreeNode *search(TreeNode *root, Key key);

    //找到键最大节点
    TreeNode *findMax(TreeNode *root);

    //找到键最小节点
    TreeNode *findMin(TreeNode *root);

    //判断节点是否为红色
    bool isRed(TreeNode *node);

    //判断节点是否为黑色
    bool isBlack(TreeNode *node);

    //初始化红黑树, 即设置根节点, 和节点数为0
    void init();

    //向左旋转
    void leftRotate(TreeNode ** root, TreeNode *node);

    //向右旋转
    void rightRotate(TreeNode ** root, TreeNode *node);

    //先序遍历, 用于测速输出, 并不在成品中使用
    void preorder(TreeNode *root);

    //中序遍历, 获取key, value和entry
    void inorder(TreeNode *root);

    //输出节点的键, 值, 颜色, 左节点, 右节点, 和父节点, 用于测试输出, 验证树结构
    void descNode(TreeNode *node);

    //向树中插入键值对
    bool insert(TreeNode **root, Key key, Value value);

    //修复插入后性质被破坏的红黑树
    void insertFixup(TreeNode **root, TreeNode *x);

    //删除键值对
    Value remove(TreeNode **root, Key key);

    //修复删除后性质被破坏的红黑树
    void removeFixup(TreeNode **root, TreeNode *x);

    //释放节点内存
    void clear(TreeNode *root);

public:
    TreeMap();
    ~TreeMap();

    //获取节点数量
    int size();

    //判断目标键值是否存在
    bool containsKey(Key key);

    //通过键获取目标值
    Value get(Key);

    //找到最小的键
    Key firstKey();

    //找到最大的键
    Key lastKey();

    //找到键最小的键值对
    Entry<Key, Value> firstEntry();

    //找到键最大的键值对
    Entry<Key, Value> lastEntry();

    //获取所有键
    std::vector<Key> keySet();

    //获取所有值
    std::vector<Value> values();

    //获取所有键值对
    std::vector<Entry<Key, Value> > entrySet();

    //插入键值对
    bool put(Key key, Value value);

    //删除键值对
    Value remove(Key key);

    //先序遍历树, 测试使用
    void output();

    //清空原来的树
    void clear();

    //更新目标键值
    bool replace(Key key, Value oldValue, Value newValue);
};

#endif // TREEMAP_H_INCLUDED
