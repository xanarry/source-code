
#include<iostream>
using namespace std;

#include<assert.h>
#include<stdlib.h>



template<typename Type>

struct LinkNode//结点类定义
{
    Type data;//数据元素
    LinkNode<Type> *pnext;//链表指针域
    //构造函数
    //仅初始化指针成员的构造函数
    LinkNode(LinkNode<Type> *next = NULL):pnext(next){}
    //初始化数据和指针成员的构造函数
    LinkNode(const Type &item, LinkNode<Type> *next = NULL):data(item),pnext(next){}
};


template<typename Type>
class SingleLinkList//单链表定义
{
public:
    //构造函数
    SingleLinkList(LinkNode<Type> *node = NULL):phead(new LinkNode<Type>(node)){ }
    SingleLinkList(Type & x){ phead = new LinkNode<Type>(x);}
    SingleLinkList(SingleLinkList &list);//复制构造函数
    ~SingleLinkList(){ setEmpty();}//析构函数

public:
    LinkNode<Type> *getHead(){ return phead; }//返回链表的头结点
    LinkNode<Type> *getRear();//获得链表的尾结点
    LinkNode<Type> *Locate(int i);//搜索第i个元素的地址
    LinkNode<Type> *Search(const Type &x);//搜索含数据x的元素
    void setEmpty();//将链表设置为空
    int getlength()const;//计算链表的长度
    //判断表是否为空，空则返回true
    bool isEmpty()const{ return phead->pnext == NULL ? true : false; }
    bool isFull()const{ return false;}//判断表是否为满，满则返回false
    bool getData(int i, Type &x);//取出第i个元素的值
    bool setData(int i, Type &x);//用x修改第i个元素的值
    bool Insert(Type &x,int i=0);//在第i个元素后插入x
    bool Remove(Type &x,int i=0);//删除第i个元素，x返回该元素的值
    bool InsertHead(Type &x);//在第1个元素前插入x，即有头结点之后插入
    bool InsertRear(Type &x);//在链表的最后后插入x
    bool RemoveHead(Type &x);//将链表中的最后一个元素删去，通过引用型参数x返回该元素的值
    bool RemoveRear(Type &x);//将链表中的最后一个元素删去，通过引用型参数x返回该元素的值

    void output()const;//输出链表中的元素

    SingleLinkList<Type> &operator=(SingleLinkList &list);//赋值重载函数
    //友元函数，操作符重载
    friend ostream& operator<<<Type>(ostream& os,const SingleLinkList<Type>& list);
private:
    LinkNode<Type> *phead;//声明头结点
};
template<typename Type>
SingleLinkList<Type>::SingleLinkList(SingleLinkList<Type> &list)//复制构造函数
{
    Type value;
    LinkNode<Type> *srcnode = list.getHead();//被复制的附加头结点地址
    LinkNode<Type> *destnode = new LinkNode<Type>();
    while(srcnode->pnext!=NULL)//逐个结点复制
    {
        value = srcnode->pnext->data;
        destnode->pnext = new LinkNode<Type>(value);
        destnode = destnode->pnext;
        srcnode = srcnode->pnext;
    }
    destnode->pnext = NULL;
}
template<typename Type>
void SingleLinkList<Type>::setEmpty()//将链表设置为空
{
    LinkNode<Type> *pDel;
    while(phead->pnext!=NULL)//当链表不为空时删去链表中所有结点
    {
        pDel = phead->pnext;//保存被删除的结点，从链上取下该结点
        phead->pnext = pDel->pnext;//删除，仅保留头结点
        delete pDel;
    }
}
template<typename Type>
int SingleLinkList<Type>::getlength() const//计算带附加结点的单链表的长度
{
    LinkNode<Type> *pMove = phead->pnext;
    int nCount = 0;
    while(pMove!=NULL)//链表扫描，寻找链尾
    {
        nCount++;
        pMove = pMove->pnext;
    }
    return nCount;
}
template<typename Type>
LinkNode<Type> *SingleLinkList<Type>::getRear()//获得链表的尾结点
{
    LinkNode<Type> *pMove = phead;
    while(pMove->pnext!=NULL)
    {
        pMove = pMove->pnext;
    }
    return pMove;
}
template<typename Type>
LinkNode<Type> *SingleLinkList<Type>::Locate(int i)
{//定位函数，返回表中第i个元素的地址，若i<0或i超出表中结点个数，则返回NULL
    if( i < 0 ) return NULL;//i不合理
    LinkNode<Type> *pMove = phead;
    int k = 0;
    while(pMove->pnext!=NULL && k<i)//寻找第i个结点
    {
        pMove = pMove->pnext;
        k++;
    }
    //返回第i个结点地址，若返回NULL,表示i值太大或太小
    return pMove;
}

template<typename Type>
LinkNode<Type> *SingleLinkList<Type>::Search(const Type &x)
{//在表中搜索含数据x的结点，搜索成功时函数返回该结点的地址，否则返回NULL值
    LinkNode<Type> *pCurrent = phead->pnext;
    while(pCurrent==NULL)
    {
        if(pCurrent->data != x)//循环链找含x的结点
            break;
        else
            pCurrent = pCurrent->pnext;   
    }
    return pCurrent;
}

template<typename Type>
bool SingleLinkList<Type>::getData(int i, Type &x)
{//取出链表中第i个元素的值
    LinkNode<Type> *pCurrent = Locate(i);
    if(pCurrent==NULL||pCurrent==phead) return false;//i不合理
    x = pCurrent->data;
    return true;
}

template<typename Type>
bool SingleLinkList<Type>::setData(int i, Type &x)
{//给链表中第i个元素赋值
    LinkNode<Type> *pCurrent = Locate(i);
    if(pCurrent==NULL||pCurrent==phead) return false;//i不合理
    pCurrent->data = x;
    return true;
}

template<typename Type>
bool SingleLinkList<Type>::Insert(Type &x, int i)//在第i个元素后插入x
{
    LinkNode<Type> *pCurrent = Locate(i);
    if(pCurrent==NULL) return false;
    LinkNode<Type> *newNode = new LinkNode<Type>(x);
    assert(newNode!=NULL);
    newNode->pnext = pCurrent->pnext;
    pCurrent->pnext = newNode;
    return true;
}
template<typename Type>
bool SingleLinkList<Type>::InsertHead(Type &x) //即insert(0,x)
{//在第1个元素前插入x，即有头结点之后插入
    LinkNode<Type> *newNode = new LinkNode<Type>(x);
    assert(newNode!=NULL);
    newNode->pnext = phead->pnext;
    phead->pnext = newNode;
    return true;
}

template<typename Type>
bool SingleLinkList<Type>::InsertRear(Type &x)
{//在链表的最后后插入x
    LinkNode<Type> *prear = getRear();
    LinkNode<Type> *newNode = new LinkNode<Type>(x);
    assert(newNode!=NULL);
    newNode->pnext = prear->pnext;
    prear->pnext = newNode;
    return true;
}

template<typename Type>
bool SingleLinkList<Type>::Remove(Type &x, int i)
{//将链表中的第i个元素删去，通过引用型参数x返回该元素的值
    LinkNode<Type> *pCurrent = Locate(i-1);
    if(pCurrent==NULL||pCurrent->pnext==NULL) return false;
    LinkNode<Type> *pDel;
    pDel = pCurrent->pnext;//重新拉链，将被删除的结点从链表中取出
    pCurrent->pnext = pDel->pnext;
    x = pDel->data;//取出被删除结点中的数据值
    delete pDel;
    return true;
}
template<typename Type>
bool SingleLinkList<Type>::RemoveHead(Type &x)
{//将链表中的第1个元素删去，通过引用型参数x返回该元素的值
    LinkNode<Type> *pDel;
    if(phead->pnext==NULL) return false;
    pDel = phead->pnext;
    phead->pnext = pDel->pnext;
    x = pDel->data;
    delete pDel;
    return true;
}
template<typename Type>
bool SingleLinkList<Type>::RemoveRear(Type &x)
{//将链表中的最后一个元素删去，通过引用型参数x返回该元素的值
    if(phead->pnext==NULL) return false;
    LinkNode<Type> *pCurrent = phead;
    while(pCurrent->pnext->pnext!=NULL)
    {
        pCurrent = pCurrent->pnext;
    }
    LinkNode<Type> *pDel;
    pDel = pCurrent->pnext;
    pCurrent->pnext = pDel->pnext;
    x = pDel->data;
    delete pDel;
    return true;
}

template<typename Type>
void SingleLinkList<Type>::output()const//输出链表中的元素
{
    LinkNode<Type> *pMove = phead;
    cout << "Head--->";
    while(pMove->pnext!=NULL)
    {
        pMove = pMove->pnext;
        cout << pMove->data << "--->";
    }
    cout << "End" << endl;
}

template<typename Type>
SingleLinkList<Type> &SingleLinkList<Type>::operator=(SingleLinkList &list)
{//操作符重载
    Type value;
    LinkNode<Type> *srcnode = list.getHead();
    LinkNode<Type> *destnode = new LinkNode<Type>();
    while(srcnode->pnext!=NULL)
    {
        value = srcnode->pnext->data;
        destnode->pnext = new LinkNode<Type>(value);
        destnode = destnode->pnext;
        srcnode = srcnode->pnext;
    }
    destnode->pnext = NULL;
    return *this;
}
template<typename Type>
ostream& operator<<(ostream& os,SingleLinkList<Type>& list) //友元函数，操作符重载
{//输出链表中元素的重载操作符<<
    os << "The length of the list is: " << list.getlength() << endl; // the size of stack is ouputing!
    LinkNode<Type> *pMove = list.getHead();
    os << "Head--->";
    while(pMove->pnext!=NULL) //The menmber of the stack is outputing respectively！
    {
        pMove = pMove->pnext;
        os <<  pMove->data <<  "--->";
    }
    os << "End" << endl;
    return os;
}
#endif

//Fle: Main.cpp
//Author: Jason

#include<iostream>
using namespace std;
#include"SingleLinkList.h"

int main()
{
    SingleLinkList<int> list;
    list.setEmpty();
    //测试空链表的长度
    cout << "The length of the list is " << list.getlength() << endl;
    if(list.isEmpty())
        cout << "The list is Empty! " << endl;
    else
        cout << "The list is Not Empty! " << endl;
    //向链表表中插入元素
    for(int i=0; i<10; i++)
    {
        int temp = 2*i;
        list.Insert(temp,i);
        cout << temp << " has been inserted ! \n";
        cout << "Output the list:\n";
        list.output();
        cout << "The length of the list is " << list.getlength() << endl;
        cout << endl;
    }
    //查看特定位置的元素并进行修改
    int data;
    list.getData(5,data);
    cout << "The fifth number in the list is " << data << endl;
    data = 100;
    list.setData(5,data);
    list.output();
    cout << "The fifth number in the list is modfied by " << data << endl;
    cout << endl;
    //删除链表元素
    for(int i=10; i>0; i--)
    {
        int temp = 0;
        list.Remove(temp,i);
        cout << temp << " has been deleted ! \n";
        cout << "Output the list:\n";
        list.output();
        cout << "The length of the list is " << list.getlength() << endl;
        cout << endl;
    }
    //向链表利用前插法在链表头部插入元素
    for(int i=0; i<5; i++)
    {
        int temp = 3*i;
        list.InsertHead(temp);
        cout << temp << " has been inserted at the head ! \n";
        cout << "Output the list:\n";
        list.output();
        cout << "The length of the list is " << list.getlength() << endl;
        cout << endl;
    }
    //向链表利用后插法在链表的尾部插入元素
    for(int i=0; i<5; i++)
    {
        int temp = 3*i;
        list.InsertRear(temp);
        cout << temp << " has been inserted at the end ! \n";
        cout << "Output the list:\n";
        list.output();
        cout << "The length of the list is " << list.getlength() << endl;
        cout << endl;
    }
    //从链表头部开始删除元素
    for(int i=0; i<5; i++)
    {
        int temp;
        list.RemoveHead(temp);
        cout << temp << " has been deleted ! \n";
        cout << "Output the list:\n";
        list.output();
        cout << "The length of the list is " << list.getlength() << endl;
        cout << endl;
    }
    //从链表尾部开始删除元素
    for(int i=0; i<5; i++)
    {
        int temp;
        list.RemoveRear(temp);
        cout << temp << " has been deleted ! \n";
        cout << "Output the list:\n";
        cout << list;
        cout << endl;
    }
    return 0;
}