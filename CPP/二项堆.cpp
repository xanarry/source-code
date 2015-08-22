#include <iostream>
using namespace std;

struct Node
{
    int key;//权值
    int degree;//二项树的度数
    Node *parent;//父指针
    Node *sibling;//兄弟指针
    Node *child;//子指针
};

Node *newHeap()
{
    // 开辟新的结点作为新的堆结点
    Node *heap = new Node();
    heap->key = 0x7FFFFFFF;
    heap->parent = NULL;
    heap->sibling = NULL;
    heap->child = NULL;
    return heap;
}

Node *merge(Node *heap1, Node *heap2)
{
    // 连接两个堆, 方式与合并两个有序链表一致
    Node *newOne = newHeap();
    Node *curPos = newOne;
    heap1 = heap1->sibling;
    heap2 = heap2->sibling;
    while (heap1 && heap2)
    {
        if (heap1->degree < heap2->degree)
        {
            curPos->sibling = heap1;
            heap1 = heap1->sibling;
        }
        else
        {
            curPos->sibling = heap2;
            heap2 = heap2->sibling;
        }
        curPos = curPos->sibling;
    }
    if (heap1)
        curPos->sibling = heap1;
    if (heap2)
        curPos->sibling = heap2;
    return newOne;
}

void link(Node *&y, Node *&z)
{
    // 将两个度数一样的二项树合并成一个新的二项树
    //y's key is bigger than z's key
    y->sibling = z->child; 
    z->child = y;
    y->parent = y;
    z->degree += 1;
}

void debug(Node *heap)
{
    // 输出链状二项树的信息
    heap = heap->sibling;
    while (heap)
    {
        cout << "[" << heap->key << "," << heap->degree;
        if (heap->child)
           cout <<  "," << heap->child->key;
        cout << "] ";
        heap = heap->sibling;
    }
    cout << "\b\n";
}

Node *unionHeap(Node *heap1, Node *heap2)
{
    // 合并两个堆
    Node *newHeap = merge(heap1, heap2);//将两个堆连接到一起
    Node *pre = newHeap;
    Node *cur = newHeap->sibling;

    //find pos to union
    while (cur && cur->sibling)
    {
        // 找到需要合并的位置, 即两个连续相同度数的结点
        if (cur->degree != cur->sibling->degree || (cur->sibling->sibling && cur->degree == cur->sibling->sibling->degree))
        {
            pre = cur;
            cur = cur->sibling;
        }
        // 为了保持两个二项树最小的结点一定在最上面, 需要判断key的值大小
        else if (cur->key < cur->sibling->key)
        {
            Node *next = cur->sibling;
            cur->sibling = next->sibling;
            link(next, cur);
        }
        else
        {   
            Node *next = cur->sibling;
            pre->sibling = next;
            link(cur, next);
            cur = next;
        }
    }
    return newHeap;
}

Node *insert(Node *heap, int key)
{
    // 插入新的元素入堆, 方式为将新的结点单独作为一个堆, 然后在连接合并新堆与原始堆实现插入
    if (heap == NULL)
       heap = newHeap();
    Node *tempHeap = newHeap();
    Node *keyNode = newHeap();
    keyNode->key = key;
    keyNode->degree = 0;
    tempHeap->sibling = keyNode;
    return unionHeap(heap, tempHeap);
}   

int searchMin(Node *heap)
{
    //搜索最小key, 即搜索整个链表
    Node *destHeap = NULL;
    Node *curPos = heap->sibling;
    int minKey = 0x7FFFFFFF;
    while (curPos)
    {
        if (curPos->key < minKey)
            minKey = curPos->key;
        curPos = curPos->sibling;
    }
    return minKey;
}

Node *extractMin(Node *heap)
{
/*  删除堆中的最小元素, 先找到最小元素的结点指针, 
    从链表中删除这个结点, 然后将该结点下的子结点
    逆序连接成一个新堆, 最后再合并这两个堆, 实现删除*/    
    Node *tpre = heap;
    Node *cur = heap->sibling;
    Node *dest = NULL;
    Node *next = NULL;
    Node *pre = NULL;
    int minKey = 0x7FFFFFFF;

    // 搜索目标结点
    while (cur)
    {
        if (cur->key < minKey)
        {
            minKey = cur->key;
            dest = cur;
            pre = tpre;
        }
        tpre = cur;
        cur = cur->sibling;
    }

    // 从元素堆链中删除目标结点
    pre->sibling = dest->sibling;

    //逆置目标结点的所有子结点
    cur = dest->child;
    if (cur)
        next = cur->sibling;
    pre = NULL;
    while (cur)
    {
        //此处实质是逆置单链表
        cur->sibling = pre;
        pre = cur;
        cur = next;
        if (next)
            next = next->sibling;
        else
            break;
    }
    // 添加头将逆置后的链表形成新的堆
    Node *reverseHeap = newHeap();
    reverseHeap->sibling = pre;
    //合并新的堆实现删除最小元素
    return unionHeap(heap, reverseHeap);
}

int main(int argc, char const *argv[])
{
    int a[26] = {12,3,6,18,15,7,37,8,29,10,44,28,33,25,30,23,22,48,31,17,41,45,32,24,50,55};
    const int len = 26;

    Node *heap = NULL;
    for (int i = 0; i < len; i++)
    {
        cout << "insert " << a[i] << ": ";
        heap = insert(heap, a[i]);
        debug(heap);
    }
    cout << "finish insert\n" << endl;

    for (int i = 0; i < len; i++)
    {
        int t = searchMin(heap);
        heap = extractMin(heap);
        cout << "extract " << t << ": "; debug(heap);
    }
    cout << "finish delete" << endl;

    return 0;
}
