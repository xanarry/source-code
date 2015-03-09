#include <iostream>
using namespace std;

//template <class T>
#define T int

struct Node   //链表结点 
{
    int data;
    Node *next;
};

class LinkList
{
private:
    Node *head;
public:
    LinkList();
    ~LinkList();
    void clear();//清空链表
    void insert(int i,T x);//在链表的第i个结点后插入数据x
    void del(int i,T &x);  //若存在第i个元素，通过引用参数x获取第i个元素，并删除第i个结点 
    void append(T x);// 在链表的表尾插入数据x
    void front(T x);//在链表的表头插入数据x
    void pirntAll();//输出链表中所有元素的值 
    Node * find(T x);//查找元素x,找到返回指向该结点的指针，否则返回NULL
    void reverse();//对链表逆置 
};

LinkList::LinkList()//初始化链表
{
    head = new Node;
    head->next = NULL;
}

void LinkList::front(T x)//在链表的表头插入数据x
{
    Node *_new = new Node;
    _new->data = x;
    _new->next = head->next;
    head->next = _new;
}

void LinkList::pirntAll()//遍历输出链表
{
    Node *p = head->next;
    if (p == NULL)
    {
        cout << "empty" << endl;
        exit(0);
    }
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

LinkList::~LinkList()//析构函数清理链表
{
    clear();
    head = NULL;
}

void LinkList::clear()//清空链表
{
    Node *p = head;
    Node *t;
    while (p)
    {
        t = p; 
        p = p->next;
        delete t; 
    }
    head->next = NULL;
}

void LinkList::append(T x)//在链表的表尾插入数据x
{
    Node *_new = new Node;
    _new->data = x;
    _new->next = NULL;

    Node *p = head->next;
    Node *tmp;

    if (head->next == NULL)
        head->next = _new;

    while (p)
    {
        tmp = p;
        p = p->next;
    }
    tmp->next = _new;
}

Node * LinkList::find(T x)//查找元素x
{
    cout << "findding " << x << endl;
    Node *p = head->next;
    while (p)
    {
        if (x == p->data)
        {
            return p;
            break;
        }
        p = p->next;
    }
    cout << "can not find this element" << endl;
    exit(1);
}


void LinkList::insert(int i,T x)//在链表的第i个结点后插入数据x
{
    Node *_new = new Node;
    Node *pre = head;
    Node *p = head;

    _new->data = x;
    _new->next = NULL;

    if (head == NULL)
    {
        head->next = _new;
    } 
    else
    {
        int count = 0;
        while (p && count != i)
        {
            pre = p;
            p = p->next;
            count++;
        }
        _new->next = pre->next;
        pre->next = _new;
    }
}


void LinkList::del(int i, T &x)//若存在第i个元素，通过引用参数x获取第i个元素，并删除第i个结点 
{
    int count = 0;
    Node *p = head;
    Node *tmp = head;
    while (p && count != i)
    {
        cout << p->data << endl;
        tmp = p;
        p = p->next;
        count++;
    }
    x = p->data;
    tmp->next = tmp->next->next;
    delete p;
} 


void LinkList::reverse()//对链表逆置 
{
    Node *p = head->next;
    Node *pre = head;
    Node *cur = pre->next;
    Node *pnext = NULL;

    while (cur)
    {
        pnext = cur->next;
        cur->next = pre;
        pre = cur;
        cur = pnext;
    }
    head->next->next = NULL;
    head->next = pre;
}


int main(int argc, char const *argv[])
{
    //头结点插入元素到链表
    LinkList l;
    cout << "front()" << endl;
    for (int i = 1; i <= 5; ++i)
    {
      l.front(i);
    }
    l.pirntAll();


    ////对链表实行逆置
    cout << endl;
    cout << "reverse()" << endl;
    l.reverse();
    l.pirntAll();

    
    //从链表尾插入元素
    cout << endl;
    cout << "append()" << endl;
    for (int i = 11; i <= 15; ++i)
    {
      l.append(i);
    }
    l.pirntAll();


    //删除一个位置的元素，并通过引用返回删除值
    cout << endl;
    cout << "input a location you wanna delete: ";
    int dellocation, get = 0;
    cin >> dellocation;
    l.del(dellocation, get);
    cout << "del(" << dellocation << ")" << endl;
    cout << get << "has been deleted" << endl;
    l.pirntAll();


    //在指定位置前插入元素
    cout << endl;
    cout << "input a number and a location you wanna insert: ";
    int location, n1;
    cin >> location >> n1;
    l.insert(location, n1);
    cout << "insert(" << location << ", " << n1 << ")" << endl;
    l.pirntAll();


    //查找输出的元素
    cout << endl;
    cout << "input a number you wanna find: ";
    int n;
    Node *tmp;
    cin >> n;
    tmp = l.find(n);
    cout << "yes! we find " << tmp->data << " in the LinkList" << endl;


    //清空链表
    cout << endl;
    cout << "clear()" << endl;
    l.clear();
    l.pirntAll();

    return 0;
}
