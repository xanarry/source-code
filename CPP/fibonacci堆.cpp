#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int key;//权值
    int degree;//度数
    bool mark;//
    //指向各部分的指针
    Node *left;
    Node *right;
    Node *parent;
    Node *child;
};

Node *newNode(int key)
{
    //初始化新的结点
    Node *newOne = new Node();
    newOne->key = key;
    newOne->degree = 0;
    newOne->mark = false;
    newOne->left = newOne->right = NULL;
    newOne->parent = newOne->child = NULL;
    return newOne;
}

//定义fibonacci堆的类
class FibHeap
{
public:
    FibHeap();
    ~FibHeap(){};
    //插入新的元素入堆
    void insert(int key);
    //输出跟结点列表
    void display();
    //连接两个相同度数的树到同一科树
    void link(Node *&a, Node *&b);
    //合并两个堆
    void merge(FibHeap fibheap);
    //判断是否为空
    bool isEmpty();
    //弹出最小元素
    int extractMin();
    //获取堆元素大小
    int size();
    //返回最小元素所在结点指针
    Node *getMin();

private:
    //合并堆链表中所有度数一样的树
    void consolidate();
    //交换链表中的两个结点
    void exchange(Node *&a, Node *&b);
    //指向堆中最小树的指针
    Node *min;
    //堆中的元素个数
    int n;
};

FibHeap::FibHeap()
{
    //初始化时没有任何结点, 元素个数为0
    min = NULL;
    n = 0;
}

void FibHeap::display()
{
    //遍历树根链, 输出每个结点的元素, 度数和孩子元素
    if (min)
    {
        Node *cur = min;
        do
        {
            cout << "[" << cur->key << "," << cur->degree << ",";
            if (cur->child)
                cout << cur->child->key;
            else
                cout << "nil";
            cout << "] ";

            cur = cur->right;
        } while (cur != min);
    }
    cout << endl;
}

void FibHeap::merge(FibHeap h)
{
    Node *hMin = h.getMin();
    if (hMin)
    {
        n += h.size();//跟新元素数量
        //连接两个链表
        hMin->right = min->right;
        min->right->left = hMin;
        min->right = hMin;
        hMin->left = min;

        //跟新最小指向最小结点的指针
        if (!min || hMin->key < min->key)
            min = hMin;
    }
}

void FibHeap::insert(int key)
{
    //插入新元素直接使用链表方式, 只有在删除时才涉及到合并堆
    Node *newOne = newNode(key);
    if (min == NULL)
    {
        //链表为空时直接插入
        min = newOne;
        min->left = min->right = min;
    }
    else
    {
        //连接上新的结点
        newOne->right = min->right;
        min->right->left = newOne;
        min->right = newOne;
        newOne->left = min;

        //更新最小结点指针
        if (newOne->key < min->key)
            min = newOne;
    }
    n++;
}

Node *FibHeap::getMin()
{
    return n ? min : NULL;
}

void FibHeap::link(Node *&a, Node *&b)
{
    //a的键值比b的小,将b连接到a上
    //更新最小指针
    min = a;

    //从原链表中删除b
    b->left->right = b->right;
    b->right->left = b->left;

    b->parent = a;//设b的parent为a
    if (a->child == NULL)
    {
        //如果a没有孩子, 那么现在b是a的唯一孩子, 设置b为双向循环链表中的唯一结点
        b->right = b;
        b->left = b;
    }
    else
    {
        //如果a有孩子, 那么将b连接到a的孩子列表上
        b->right = a->child;
        b->left = a->child->left;
        a->child->left->right = b;
        a->child->left = b;
    }
    //更新a的孩子为b
    a->child = b;
    //更新结点a的度数
    a->degree += 1;
}

void FibHeap::exchange(Node *&a, Node *&b)
{
    //交换链表中的两个结点
    //cout << "exchange: " << a->key << " with " << b->key << endl;

    //如果a,b相邻且b在a的右边
    if (a->right == b)
    {
        //cout << a->key << "'s right is: " << b->key << endl;
        Node *temp = a;
        //先删除a
        a->left->right = b;
        b->left = a->left;

        //再在b的右边连接上a实现交换
        temp->right = b->right;
        b->right->left = temp;
        b->right = temp;
        temp->left = b;

        //交换指针
        a = b;
        b = temp;
    }
    //如果a,b相邻且b在a的左边
    else if (a->left == b)
    {
        //cout << a->key << "'s left is: " << b->key << endl;
        //从链表中删除a
        Node *temp = a;
        b->right = a->right;
        a->right->left = b;
        
        //再在b的左边插入a
        b->left->right = temp;
        temp->left = b->left;
        temp->right = b;
        b->left = temp;

        //交换指针
        a = b;
        b = temp;
    }
    else
    {
        //cout << a->key << " and " << b->key << " is not adjacent" << endl;
        //交换的两个结点不相邻, 先标记两个结点的位置, 然后从链表删除两个结点, 再在a的位置插入b,在b的位置插入a
        //标记a,b的位置
        Node *aPos = a->left;
        Node *bPos = b->left;

        //标记a,b结点
        Node *ta = a;
        Node *tb = b;

        //删除a
        aPos->right = a->right;
        a->right->left = aPos;

        //删除b
        bPos->right = b->right;
        b->right->left = bPos;

        //将b重新插入a的位置
        tb->right = aPos->right;
        aPos->right->left = tb;
        aPos->right = tb;
        tb->left = aPos;

        //将a重新插入b的位置
        ta->right = bPos->right;
        bPos->right->left = ta;
        bPos->right = ta;
        ta->left = bPos;

        //交换指针
        a = tb;
        b = ta;
    }
}

void FibHeap::consolidate()
{
    int len = 2 * (1 + log(n) / log(2));//计算数组长度
    //申请数组并初始化
    Node *assis[len];
    for (int i = 0; i < len; i++)
        assis[i] = NULL;

    Node *cur = min;//标记起点位置
    while (true)//遍历每个结点
    {
        int degree = cur->degree;
        if (assis[degree] == cur)
            break;//如果最有合并同一个结点, 说明所有结点已经遍历一遍了, 终止循环
        while (assis[degree] != NULL)
        {   
            //连续合并度数一样的结点
            if (cur->key > assis[degree]->key)
                exchange(cur, assis[degree]);
            link(cur, assis[degree]);
            assis[degree] = NULL;
            degree++;
        }
        assis[degree] = cur;
        cur = cur->right;
    }
    //更新min指针指向最元素结点
    for (int i = 0; i < len; i++)
        if (assis[i] && (!min || assis[i]->key < min->key))
            min = assis[i];
}

int FibHeap::extractMin()
{
    //弹出最小元素, 方法:找到最小元素, 然后将其所有孩子结点放入跟链表中, 执行consolidate函数合并
    if (n == 0)//如果堆中没有结点, 返回-1
        return -1;

    Node *temp = min;//标记最小结点
    int minKey = temp->key;//保存返回值

    if (min->right == min)//如果跟链表中只有一个结点
        min = temp->child;//直接将孩子链表设为跟链表
    else {
        //标记要删除结点的左右边指针, 和孩子指针
        Node *leftPos = min->left;
        Node *rightPos = min->right;
        Node *children = min->child;
        //更新min指针
        min = min->right;
        if (children == NULL)//如果孩子为空链表, 直接将原始链表排除最小结点连上
        {
            leftPos->right = min;
            min->left = leftPos;
        }
        else
        {
            //将孩子链表在断开出连接到原始链表中
            leftPos->right = children;
            children->left->right = rightPos;
            rightPos->left = children->left;
            children->left = leftPos;
        }
    }
    //释放删除结点的内存
    delete temp;
    n--;//更新数量
    if (n > 0)//如果元素的数量大于0才有必要整理链表
       consolidate();
    return minKey;
}

int FibHeap::size()
{
    return n;
}

bool FibHeap::isEmpty()
{
    return n > 0 ? false : true;
}

int main(int argc, char const *argv[])
{
    FibHeap fibheap;
    const int len = 15;
    int a[] = {23,7,21,3,17,24,18,52,38,30,26,46,39,41,35};
    
    for (int i = 0; i < len; i++)
    {
        fibheap.insert(a[i]);fibheap.display();
    }
    cout << "finish insert" << endl;

    cout << fibheap.size() << endl;

    for (int i = 0; i < len; i++)
    {
        cout << "ex: " << fibheap.extractMin() << " "; fibheap.display();
    }
    cout << "finish delete" << endl;
    return 0;
}
