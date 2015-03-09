#include <iostream>
using namespace std;

//template <class T>
#define T int

struct Node   //������ 
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
    void clear();//�������
    void insert(int i,T x);//������ĵ�i�������������x
    void del(int i,T &x);  //�����ڵ�i��Ԫ�أ�ͨ�����ò���x��ȡ��i��Ԫ�أ���ɾ����i����� 
    void append(T x);// ������ı�β��������x
    void front(T x);//������ı�ͷ��������x
    void pirntAll();//�������������Ԫ�ص�ֵ 
    Node * find(T x);//����Ԫ��x,�ҵ�����ָ��ý���ָ�룬���򷵻�NULL
    void reverse();//���������� 
};

LinkList::LinkList()//��ʼ������
{
    head = new Node;
    head->next = NULL;
}

void LinkList::front(T x)//������ı�ͷ��������x
{
    Node *_new = new Node;
    _new->data = x;
    _new->next = head->next;
    head->next = _new;
}

void LinkList::pirntAll()//�����������
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

LinkList::~LinkList()//����������������
{
    clear();
    head = NULL;
}

void LinkList::clear()//�������
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

void LinkList::append(T x)//������ı�β��������x
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

Node * LinkList::find(T x)//����Ԫ��x
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


void LinkList::insert(int i,T x)//������ĵ�i�������������x
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


void LinkList::del(int i, T &x)//�����ڵ�i��Ԫ�أ�ͨ�����ò���x��ȡ��i��Ԫ�أ���ɾ����i����� 
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


void LinkList::reverse()//���������� 
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
    //ͷ������Ԫ�ص�����
    LinkList l;
    cout << "front()" << endl;
    for (int i = 1; i <= 5; ++i)
    {
      l.front(i);
    }
    l.pirntAll();


    ////������ʵ������
    cout << endl;
    cout << "reverse()" << endl;
    l.reverse();
    l.pirntAll();

    
    //������β����Ԫ��
    cout << endl;
    cout << "append()" << endl;
    for (int i = 11; i <= 15; ++i)
    {
      l.append(i);
    }
    l.pirntAll();


    //ɾ��һ��λ�õ�Ԫ�أ���ͨ�����÷���ɾ��ֵ
    cout << endl;
    cout << "input a location you wanna delete: ";
    int dellocation, get = 0;
    cin >> dellocation;
    l.del(dellocation, get);
    cout << "del(" << dellocation << ")" << endl;
    cout << get << "has been deleted" << endl;
    l.pirntAll();


    //��ָ��λ��ǰ����Ԫ��
    cout << endl;
    cout << "input a number and a location you wanna insert: ";
    int location, n1;
    cin >> location >> n1;
    l.insert(location, n1);
    cout << "insert(" << location << ", " << n1 << ")" << endl;
    l.pirntAll();


    //���������Ԫ��
    cout << endl;
    cout << "input a number you wanna find: ";
    int n;
    Node *tmp;
    cin >> n;
    tmp = l.find(n);
    cout << "yes! we find " << tmp->data << " in the LinkList" << endl;


    //�������
    cout << endl;
    cout << "clear()" << endl;
    l.clear();
    l.pirntAll();

    return 0;
}
