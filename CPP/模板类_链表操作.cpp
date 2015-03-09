#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
struct Node   //����ṹ�� 
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
    void clear();//�������
    void insert(int i, T x);//������ĵ�i�������������x
    void del(int i, T &x);//�����ڵ�i��Ԫ�أ�ͨ�����ò���x��ȡ��i��Ԫ�أ���ɾ����i����� 
    void append(T x);//������ı�β��������x
    void front(T x);//������ı�ͷ��������x
    void printALL();//�������������Ԫ�ص�ֵ  
    Node<T> * find(T x);//����Ԫ��x,�ҵ�����ָ��ý���ָ�룬���򷵻�NULL
    void reverse();//���������� 
    Node<T> * gethead();//��ȡͷ���
};

template <class T>
Node<T> * LinkList<T>::gethead()
{
	return head;
}

template <class T>
LinkList<T>::LinkList()//��ʼ������
{
    head = new Node<T>;
    head->next = NULL;
}

template <class T>
void LinkList<T>::front(T x)//������ı�ͷ��������x
{
    Node<T> *_new = new Node<T>;
    _new->data = x;
    _new->next = head->next;
    head->next = _new;
}

template <class T>
void LinkList<T>::printALL()//�������������Ԫ�ص�ֵ  
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
LinkList<T>::~LinkList()//��������
{
    clear();
    head = NULL;
}

template <class T>
void LinkList<T>::clear()//�������
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
void LinkList<T>::append(T x)//��β������Ԫ��
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
Node<T> * LinkList<T>::find(T x)//����Ԫ��x
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
void LinkList<T>::insert(int i,T x)//ָ��λ�ò���Ԫ��
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
void LinkList<T>::del(int i, T &x)//ָ��λ��ɾ��Ԫ�أ�ͨ�����÷���ɾ��Ԫ��ֵ
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
void LinkList<T>::reverse()//��������
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

//主函�//
int main(int argc, char const *argv[])
{
    //ͷ������5��Ԫ��
    LinkList<int> l;
    cout << "front()" << endl;
    for (int i = 1; i <= 5; ++i)
    {
      l.front(i);
    }
    l.printALL();


    //��������
    cout << endl;
    cout << "reverse()" << endl;
    l.reverse();
    l.printALL();

    
    //β����5��Ԫ��
    cout << endl;
    cout << "append()" << endl;
    for (int i = 11; i <= 15; ++i)
    {
      l.append(i);
    }
    l.printALL();


    //ɾ��ָ��λ��Ԫ��
    cout << endl;
    cout << "input a location you wanna delete: ";
    int dellocation, get = 0;
    cin >> dellocation;
    l.del(dellocation, get);
    cout << "del(" << dellocation << ")" << endl;
    cout << get << " has been deleted" << endl;
    l.printALL();


    //ָ��λ�ò���Ԫ��
    cout << endl;
    cout << "input a number and a location you wanna insert: ";
    int location, n1;
    cin >> location >> n1;
    l.insert(location, n1);
    cout << "insert(" << location << ", " << n1 << ")" << endl;
    l.printALL();


    //����Ԫ��
    cout << endl;
    cout << "input a number you wanna find: ";
    int n;
    Node<int> *tmp;
    cin >> n;
    if (tmp = l.find(n))
    	cout << "yes! we find " << tmp->data << " in the LinkList" << endl;
    

	//�󼯺Ͻ���
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
	
	
	//��������
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
