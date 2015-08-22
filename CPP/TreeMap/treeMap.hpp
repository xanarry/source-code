/**********************************************************************
    文件描述: treemap的函数实现
    命名约定: 所有变量和函数均使用驼峰式命名方式, 类的定义首字母大写
    完成时间: 2015-6-25
    最后修改: 2015-6-30
    auther: 熊洋(xanarry@163.com)
**********************************************************************/
#ifndef TREEMAP_HPP_INCLUDED
#define TREEMAP_HPP_INCLUDED
#include "treeMap.h"
#include <iostream>
using namespace std;

/************************************
 *          私有函数定义            *
 ************************************/

/******************************************************************
    初始化TreeMap
    设置nil节点, 树中的所有NULL指针都指向nil节点
    空树时只有一个nil节点, 树根就为nil, 节点数量为0
******************************************************************/  
template<typename Key, typename Value>
void TreeMap<Key, Value>::init()
{
    this->nil = this->getNil();
    rbt = nil;
    nodeCount = 0;
}

/***********************************************************************************************
    生成nil节点
    nil节点表示NULL节点, 所以该节点的颜色为黑色
    节点的left, right, parent指针都指向自身, 其中parent指针在删除表示双黑节点时会指向其他节点
***********************************************************************************************/
template<typename Key, typename Value>
typename TreeMap<Key, Value>::TreeNode * TreeMap<Key, Value>::getNil()
{
    TreeNode *nil = new TreeNode();
    nil->parent = nil;
    nil->left = nil;
    nil->right = nil;
    nil->color = BLACK;
    return nil;
}

/**********************************************************************  
    生成新的树节点
    为了使新插入节点后对红黑树的性质破坏最小, 新节点的颜色都为红色
    保存键值对, 并设置左右指针为nil和父指针
**********************************************************************/
template<typename Key, typename Value>
typename TreeMap<Key, Value>::TreeNode * TreeMap<Key, Value>::newNode(TreeNode *parent, Key key, Value value)
{
    TreeNode *newOne = new TreeNode();//申请新的节点

    if (newOne == NULL)//检查是否有效
        return NULL;

    newOne->parent = parent;//设置父指针

    newOne->entry = Entry<Key, Value>(key, value);//保存键值对
    newOne->color = RED;
    newOne->left = nil;
    newOne->right = nil;
    return newOne;
}

/************************************************************************
    搜索任意节点
    在树中搜索节点, 搜索成功返回目标节点的指针, 失败则返回nil
************************************************************************/
template<typename Key, typename Value>
typename TreeMap<Key, Value>::TreeNode * TreeMap<Key, Value>::search(TreeNode *root, Key key)
{
    while (root != nil && root->entry.key != key)
    {
        if (key > root->entry.key)
            root = root->right;
        else if (key < root->entry.key)
            root = root->left;
    }
    return root;
}

/********************************************************************
    搜索键最大值
    根据二叉树的性质, 最大的节点一定在最右边, 所有不断向右搜索
********************************************************************/
template<typename Key, typename Value>
typename TreeMap<Key, Value>::TreeNode * TreeMap<Key, Value>::findMax(TreeNode *root)
{
    while (root != nil && root->right != nil)
        root = root->right;
    return root;
}

/********************************************************************
    搜索键最小值
    根据二叉树的性质, 最大的节点一定在最左边, 所有不断向左搜索
********************************************************************/
template<typename Key, typename Value>
typename TreeMap<Key, Value>::TreeNode * TreeMap<Key, Value>::findMin(TreeNode *root)
{
    while (root != nil && root->left != nil)
        root = root->left;
    return root;
}

/**************************************
    检查节点的颜色是不是红色
***************************************/
template<typename Key, typename Value>
bool TreeMap<Key, Value>::isRed(TreeNode *node)
{
    return (node != nil && node->color == RED) ? true : false;
}

/**************************************
    检查节点是不是黑色
***************************************/
template<typename Key, typename Value>
bool TreeMap<Key, Value>::isBlack(TreeNode *node)
{
    return !isRed(node);//不是红色一定是黑色
}

/**************************************
    向左旋转树
**************************************/
template<typename Key, typename Value>
void TreeMap<Key, Value>::leftRotate(TreeNode ** root, TreeNode *node)
{
    TreeNode *rightChild = node->right;//找到即将上移的节点
    node->right = rightChild->left;

    if (rightChild->left != nil)//子节点的父节点设置, 非常重要, 否则会出难以检查的错误结果
        rightChild->left->parent = node;

    rightChild->parent = node->parent;

    if (node->parent == nil)
        *root = rightChild;
    else
    {
        if (node == node->parent->left)
            node->parent->left = rightChild;
        else if (node == node->parent->right)
            node->parent->right = rightChild;
    }
    rightChild->left = node;
    node->parent = rightChild;
}

/**************************************
    向右旋转树
**************************************/
template<typename Key, typename Value>
void TreeMap<Key, Value>::rightRotate(TreeNode **root, TreeNode *node)
{
    TreeNode *leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right != nil)
        leftChild->right->parent = node;

    leftChild->parent = node->parent;

    if (node->parent == nil)
        *root = leftChild;
    else
    {
        if (node == node->parent->left)
            node->parent->left = leftChild;
        else if (node == node->parent->right)
            node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

/**************************************
    先序遍历
**************************************/
template<typename Key, typename Value>
void TreeMap<Key, Value>::preorder(TreeNode *root)
{
    if (root != nil)
    {
        descNode(root);
        preorder(root->left);
        preorder(root->right);
    }
}

/**************************************
    中序遍历, 同时获取键, 值, 键值对
**************************************/
template<typename Key, typename Value>
void TreeMap<Key, Value>::inorder(TreeNode *root)
{
    if (root != nil)
    {
        inorder(root->left);
        KeySet.push_back(root->entry.key);
        Values.push_back(root->entry.value);
        EntrySet.push_back(root->entry);
        inorder(root->right);
    }
}

/**************************************
    输出节点信息
**************************************/
template<typename Key, typename Value>
void TreeMap<Key, Value>::descNode(TreeNode *node)
{
    std::cout << "[key(" << (node != nil ? node->entry.key : -1) << "," << (node->color ? "red)" : "blk)");

    cout << "  val( " << node->entry.value << " )";
    if (node->parent != nil)
        std::cout << "  pant(" << node->parent->entry.key << "," << (node->parent->color ? "red)" : "blk)");
    else
        std::cout << "  pant( null )";

    if (node->left != nil)
        std::cout << "  left(" << node->left->entry.key << "," << (node->left->color ? "red)" : "blk)");
    else
        std::cout << "  left( null )";

    if (node->right != nil)
        std::cout << "  rigt(" << node->right->entry.key << "," << (node->right->color ? "red)" : "blk)");
    else
        std::cout << "  rigt( null )";
    std::cout << "]" << std::endl;
}

/*********************************************************************
    插入新的节点 
    以普通二叉树的方式插入, 然后使用insertFixup修复性质
    如果插入重复的键, 那么后面的值将覆盖前面的值
*********************************************************************/
template<typename Key, typename Value>
bool TreeMap<Key, Value>::insert(TreeNode **root, Key key, Value value)
{

    TreeNode *parent = (*root)->parent;
    TreeNode *curPos = *root;

    //找到应该插入的位置
    while (curPos != nil && curPos->entry.key != key)
    {
        parent = curPos;
        if (key > curPos->entry.key)
            curPos = curPos->right;
        else if (key < curPos->entry.key)
            curPos = curPos->left;
    }

    //如果插入的键已经存在, 那么更新其值
    if (curPos != nil && curPos->entry.key == key)
    {
        curPos->entry.value = value;
        return true;
    }

    //创建新的节点
    TreeNode *newOne = newNode(parent, key, value);
    //检查节点是否有效
    if (newOne == NULL)
        return false;

    //将节点链接到树上
    if (curPos == nil && parent == nil)
        *root = newOne;
    else if (key > parent->entry.key)
        parent->right = newOne;
    else if (key < parent->entry.key)
        parent->left = newOne;

    //修复树的性质
    insertFixup(root, newOne);
    //节点数量加1
    nodeCount++;
    return true;
}

/***********************************************************************
    修复插入性质被破坏的树
    分为两种情况, 一种是叔叔是红色, 另外一种是叔叔是黑色
    当叔叔为红色的时候, 将祖父的颜色设为红色, 叔叔和父亲的颜色设为黑色
    当叔叔的颜色为黑色的时候, 旋转节点, 并重新染色
    以上两种情况在分为左右两种
***********************************************************************/
template<typename Key, typename Value>
void TreeMap<Key, Value>::insertFixup(TreeNode **root, TreeNode *x)
{
    while (isRed(x->parent))
    {
        //插入的节点在根节点的左边
        if (x->parent == x->parent->parent->left)
        {
            TreeNode *aunt = x->parent->parent->right;
            //case 1: 叔叔是红色, 交换叔叔, 父亲与祖父的颜色, 修复的节点上移到祖父位置
            if (isRed(aunt))
            {
                x->parent->parent->color = RED;
                x->parent->color = BLACK;
                aunt->color = BLACK;
                x = x->parent->parent;
            }
            //case 2: 叔叔的颜色是黑色, 需要旋转, 如果是LR型则需要两次旋转
            else
            {
                //LR类型的先旋转一次转化为LL类型
                if (x == x->parent->right)
                {
                    //旋转后x原指向的节点会上移, 而x的父亲会下移, 所有将x置为x父亲
                    //保证旋转后x的位置还是在原有的高度, 而不会上移一个高度
                    x = x->parent;
                    leftRotate(root, x);
                }
                //x本身是红色的,此时x与x的父亲都是红色的的,那么将祖父的颜色设为红色, 
                //将父亲的颜色设为黑色, 然后旋转祖父节点调整性质
                x->parent->parent->color = RED;
                x->parent->color = BLACK;
                rightRotate(root, x->parent->parent);
            }
        }
        //插入节点在右边, 情况与在左边一样, 呈镜像对称
        else
        {
            TreeNode *aunt = x->parent->parent->left;
            if (isRed(aunt))
            {
                x->parent->parent->color = BLACK;
                x->parent->color = BLACK;
                aunt->color = BLACK;
                x = x->parent->parent;
            }
            else
            {
                if (x == x->parent->left)
                {
                    x = x->parent;
                    rightRotate(root, x);
                }
                x->parent->parent->color = RED;
                x->parent->color = BLACK;
                leftRotate(root, x->parent->parent);
            }
        }
    }
    //最有将树根颜色置为黑色
    (*root)->color = BLACK;
}


/**********************************************************************
    删除函数
    删除的方式与普通二叉树的方式一样, 但要处理额外的parent指针
    然后使用removeFixup修复性质
    值得注意的是如果删除的是红色节点不会影响树的性质, 所有只有当删除的
    节点是黑色的时候才用修复
**********************************************************************/
template<typename Key, typename Value>
Value TreeMap<Key, Value>::remove(TreeNode **root, Key key)
{
    //搜索是否存在目标节点, 存在则删除
    TreeNode *res = search(*root, key);
    if (res != nil)
    {
        //获取将要删除的节点的键
        Value deleteV = res->entry.value;

        //如果目标有两个子数, 那么则删除前驱节点或者后继节点
        //找到实际上会删除的节点
        TreeNode *actuallDelete = (res->left != nil && res->right != nil) ? findMax(res->left) : res;
        
        //找到含有额外一重黑色的节点
        TreeNode *doubleBlack = actuallDelete->left != nil ? actuallDelete->left : actuallDelete->right;

        //设置双黑节点的父节点
        doubleBlack->parent = actuallDelete->parent;

        //键双黑节点链接到树中
        if (actuallDelete->parent == nil)//输入删除的是跟节点
            *root = doubleBlack;
        else if (actuallDelete == actuallDelete->parent->left)
            actuallDelete->parent->left = doubleBlack;
        else if (actuallDelete == actuallDelete->parent->right)
            actuallDelete->parent->right = doubleBlack;

        //删除的是其他替换节点则将替换节点的值复制过来
        if (actuallDelete != res)
            res->entry = actuallDelete->entry;

        if (isBlack(actuallDelete))//删除的的黑色节点,修复性质
            removeFixup(root, doubleBlack);

        //释放节点内存
        delete actuallDelete;
        //节点数量减1
        nodeCount--;
        return deleteV;
    }
}

/*******************************************************************************
    以下的解决方案均为左边的, 右边的对称即可, case 4 为结束情况
    删除后修复性质分左右各分四种情况

    case 1: 双黑节点的兄弟节点是红色的
        solution: 交换父节点和兄弟节点的颜色, 然后向左旋转, 转化为后面的情况

    case 2: 双黑节点的兄弟是黑色节点, 并且兄弟的两个孩子都是黑色
        solution: 将兄弟的颜色设为红色, 上移修复节点

    case 3: 兄弟为黑色, 并且兄弟左边的孩子为红色, 右边的为黑色
        sloution: 交换兄弟左边孩子与兄弟的颜色, 右旋兄弟

    case 4: 兄弟为黑色, 右边的为红色, 
        solution: 将兄弟设为父亲的颜色, 然后将父亲和兄弟右边的孩子都设为黑色, 
                  左旋x的父节点, 完成调整
*******************************************************************************/
template<typename Key, typename Value>
void TreeMap<Key, Value>::removeFixup(TreeNode **root, TreeNode *x)
{
    while (x != *root && isBlack(x))
    {
        //双黑节点在左边
        if (x == x->parent->left)
        {
            TreeNode *sibling = x->parent->right;
            //case 1: 双黑节点的兄弟节点是红色的
            if (isRed(sibling))
            {
                //交换颜色并左旋转
                sibling->color = BLACK;
                x->parent->color = RED;
                leftRotate(root, x->parent);
                sibling = x->parent->right;
            }
            //case 2: 双黑节点的兄弟是黑色节点, 并且兄弟的两个孩子都是黑色
            if (isBlack(sibling->left) && isBlack(sibling->right))
            {
                //将兄弟的颜色设为红色, 上移x
                sibling->color = RED;
                x = x->parent;
            }
            else
            {
                //case 3: 兄弟为黑色, 并且兄弟左边的孩子为红色, 右边的为黑色
                if (isBlack(sibling->right))
                {
                    //交换兄弟和其左孩子的颜色
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    //右旋
                    rightRotate(root, sibling);
                    sibling = x->parent->right;
                }

                //case 4: 兄弟为黑色, 右边的为红色, 
                //将兄弟设为父亲的颜色, 然后将父亲和兄弟右边的孩子都设为黑色, 左旋x的父节点, 完成调整
                sibling->color = x->parent->color;
                x->parent->color = BLACK;
                sibling->right->color = BLACK;
                leftRotate(root, x->parent);
                x = *root;
            }
        }
        //双黑节点在右边
        else
        {
            TreeNode *sibling = x->parent->left;
            if (isRed(sibling))
            {
                x->parent->color = RED;
                sibling->color = BLACK;
                rightRotate(root, x->parent);
                sibling = x->parent->left;
            }
            if (isBlack(sibling->left) && isBlack(sibling->right))
            {
                sibling->color = RED;
                x = x->parent;
            }
            else
            {
                if (isBlack(sibling->left))
                {
                    sibling->color = RED;
                    x->right->color = BLACK;
                    leftRotate(root, sibling);
                    sibling = x->parent->left;
                }
                sibling->color = x->parent->color;
                x->parent->color = BLACK;
                sibling->left->color = BLACK;
                rightRotate(root, x->parent);
                x = *root;
            }
        }
    }
    x->color = BLACK;
}

/*******************************************
    后序遍历释放每个节点的内存
*******************************************/
template<typename Key, typename Value>
void TreeMap<Key, Value>::clear(TreeNode *root)
{
    if (root != nil)
    {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}


/**************************************************
 *              公共函数定义                      *
 **************************************************/

//定义treemap初始化map
template<typename Key, typename Value>
TreeMap<Key, Value>::TreeMap()
{
    init();
}

//释放掉treemap
template<typename Key, typename Value>
TreeMap<Key, Value>::~TreeMap()
{
    clear(rbt);//删除所有数节点
    delete nil;//删除nil节点
}

//获取节点数量
template<typename Key, typename Value>
int TreeMap<Key, Value>::size()
{
    return nodeCount;
}

//判断目标键值是否存在
template<typename Key, typename Value>
bool TreeMap<Key, Value>::containsKey(Key key)
{
    return search(rbt, key) != nil ? true : false;
}

//通过键获取目标值
template<typename Key, typename Value>
Value TreeMap<Key, Value>::get(Key key)
{
    return search(rbt, key)->entry.value;
}

//找到最小的键
template<typename Key, typename Value>
Key TreeMap<Key, Value>::firstKey()
{
    return findMin(rbt)->entry.key;
}

//找到最大的键
template<typename Key, typename Value>
Key TreeMap<Key, Value>::lastKey()
{
    return findMax(rbt)->entry.key;
}

//找到键最小的键值对
template<typename Key, typename Value>
Entry<Key, Value> TreeMap<Key, Value>::firstEntry()
{
    return findMin(rbt)->entry;
}

//找到键最大的键值对
template<typename Key, typename Value>
Entry<Key, Value> TreeMap<Key, Value>::lastEntry()
{
    return findMax(rbt)->entry;
}

//获取所有键
template<typename Key, typename Value>
vector<Key> TreeMap<Key, Value>::keySet()
{
    this->KeySet.clear();
    inorder(rbt);
    return this->KeySet;
}

//获取所有值
template<typename Key, typename Value>
vector<Value> TreeMap<Key, Value>::values()
{
    Values.clear();
    inorder(rbt);
    return Values;
}

//获取所有键值对
template<typename Key, typename Value>
vector<Entry<Key, Value> > TreeMap<Key, Value>::entrySet()
{
    EntrySet.clear();
    inorder(rbt);
    return EntrySet;
}

//插入键值对
template<typename Key, typename Value>
bool TreeMap<Key, Value>::put(Key key, Value value)
{
    return insert(&rbt, key, value);
}

//删除键值对
template<typename Key, typename Value>
Value TreeMap<Key, Value>::remove(Key key)
{
    return remove(&rbt, key);
}

//更新目标键值
template<typename Key, typename Value>
bool TreeMap<Key, Value>::replace(Key key, Value oldValue, Value newValue)
{
    TreeNode *res = search(rbt, key);
    if (res != nil && res->entry.value == oldValue)
    {
        res->entry.value = newValue;
        return true;
    }
    return false;
}

//清空原来的树
template<typename Key, typename Value>
void TreeMap<Key, Value>::clear()
{
    clear(rbt);
    init();
}

//先序遍历树, 测试使用
template<typename Key, typename Value>
void TreeMap<Key, Value>::output()
{
    std::cout << "-----------------------------------------------------------------" << endl;
    preorder(rbt);
    std::cout << "-----------------------------------------------------------------\n" << endl;
}

#endif // TREEMAP_HPP_INCLUDED
