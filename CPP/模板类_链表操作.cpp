#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
struct Node   //链表结构体 
{
    T data;
    Node<T> *next;
};

template <class T>
class LinkList
{
private:
    Node<T> *head;
public:
    LinkList();
    ~LinkList();
    void clear();//清空链表
    void insert(int i, T x);//在链表的第i个结点后插入数据x
    void del(int i, T &x);//若存在第i个元素，通过引用参数x获取第i个元素，并删除第i个结点 
    void append(T x);//在链表的表尾插入数据x
    void front(T x);//在链表的表头插入数据x
    void printALL();//输出链表中所有元素的值  
    Node<T> * find(T x);//查找元素x,找到返回指向该结点的指针，否则返回NULL
    void reverse();//对链表逆置 
    Node<T> * gethead();//获取头结点
};

template <class T>
Node<T> * LinkList<T>::gethead()
{
	return head;
}

template <class T>
LinkList<T>::LinkList()//初始化链表
{
    head = new Node<T>;
    head->next = NULL;
}

template <class T>
void LinkList<T>::front(T x)//在链表的表头插入数据x
{
    Node<T> *_new = new Node<T>;
    _new->data = x;
    _new->next = head->next;
    head->next = _new;
}

template <class T>
void LinkList<T>::printALL()//输出链表中所有元素的值  
{
    Node<T> *p = head->next;
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

template <class T>
LinkList<T>::~LinkList()//析构函数
{
    clear();
    head = NULL;
}

template <class T>
void LinkList<T>::clear()//清空链表
{
    Node<T> *p = head;
    Node<T> *t;
    while (p)
    {
        t = p; 
        p = p->next;
        delete t; 
    }
    head->next = NULL;
}

template <class T>
void LinkList<T>::append(T x)//向尾部插入元素
{
    Node<T> *_new = new Node<T>;
    _new->data = x;
    _new->next = NULL;

    Node<T> *p = head;
    Node<T> *tmp;
    
    while (p)
    {
        tmp = p;
        p = p->next;
    }
    
    tmp->next = _new;
}

template <class T>
Node<T> * LinkList<T>::find(T x)//查找元素x
{
    cout << "findding " << x << endl;
    Node<T> *p = head->next;
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
    return 0;
}

template <class T>
void LinkList<T>::insert(int i,T x)//指定位置插入元素
{
    Node<T> *_new = new Node<T>;
    Node<T> *pre = head;
    Node<T> *p = head;

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

template <class T>
void LinkList<T>::del(int i, T &x)//指定位置删除元素，通过引用返回删除元素值
{
    int count = 0;
    Node<T> *p = head;
    Node<T> *tmp = head;
    while (p && count != i)
    {
        tmp = p;
        p = p->next;
        count++;
    }
    x = p->data;
    tmp->next = tmp->next->next;
    delete p;
} 

template <class T>
void LinkList<T>::reverse()//逆置链表
{
    Node<T> *pre = head;
    Node<T> *cur = pre->next;
    Node<T> *pnext = NULL;

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

//涓诲嚱鏁//
int main(int argc, char const *argv[])
{
    //头结点插入5个元素
    LinkList<int> l;
    cout << "front()" << endl;
    for (int i = 1; i <= 5; ++i)
    {
      l.front(i);
    }
    l.printALL();


    //逆置链表
    cout << endl;
    cout << "reverse()" << endl;
    l.reverse();
    l.printALL();

    
    //尾插入5个元素
    cout << endl;
    cout << "append()" << endl;
    for (int i = 11; i <= 15; ++i)
    {
      l.append(i);
    }
    l.printALL();


    //删除指定位置元素
    cout << endl;
    cout << "input a location you wanna delete: ";
    int dellocation, get = 0;
    cin >> dellocation;
    l.del(dellocation, get);
    cout << "del(" << dellocation << ")" << endl;
    cout << get << " has been deleted" << endl;
    l.printALL();


    //指定位置插入元素
    cout << endl;
    cout << "input a number and a location you wanna insert: ";
    int location, n1;
    cin >> location >> n1;
    l.insert(location, n1);
    cout << "insert(" << location << ", " << n1 << ")" << endl;
    l.printALL();


    //查找元素
    cout << endl;
    cout << "input a number you wanna find: ";
    int n;
    Node<int> *tmp;
    cin >> n;
    if (tmp = l.find(n))
    	cout << "yes! we find " << tmp->data << " in the LinkList" << endl;
    

	//求集合交集
	LinkList<int> a;
	LinkList<int> b;
	for (int i = 10; i <= 20; ++i)
    {
      	a.append(i);
     	b.append(i + 5);
    }
    cout << "\nlinklist a: ";
    a.printALL();
    cout << "\nlinklist b: ";
	b.printALL();
	cout << endl;
	Node<int> *p = b.gethead()->next;
	while (p)
	{
		if (!a.find(p->data));
			a.append(p->data);
		p = p->next;
	}
	a.printALL();
	
	
	//清理链表
    cout << endl;
    cout << "clear()" << endl;
    l.clear();
    a.clear();
    b.clear();
    l.printALL();
    a.printALL();
    b.printALL();
    return 0;
}
