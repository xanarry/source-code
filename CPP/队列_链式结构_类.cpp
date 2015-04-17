#include <iostream>
using namespace std;

struct NODE//双向链表基本单元结构
{
    int data;
    NODE *next;//后继指针
    NODE *pre;//前驱指针
};

class QUEUE//定义queue类封装数据和实现
{
private:
    NODE *front;//队头指针
    NODE *tail;//队尾指针
    unsigned size;

public:
    QUEUE();
    ~QUEUE(){};
    void initialize();//初始化
    void enqueue(int n);//入队
    void dequeue();//出队
    int get_front();//获取元素
    void clear();//清空队列
    int get_size();//返回元素个数
    bool isempty();//判断是否为空
    void display_queue();//输出队列
};

QUEUE::QUEUE()
{
    initialize();
}

void QUEUE::initialize()
{
    //初始化头部和尾部指针
    front = new NODE();
    tail = new NODE();
    //将头尾连接
    front->data = tail->data = 0;
    front->pre = tail->next = NULL;
    front->next = tail;
    tail->pre = front;
    size = 0;//设置元素个数为0
}

void QUEUE::enqueue(int n)
{
    //开辟新节点
    NODE *new_ele = new NODE();
    //设置数据
    new_ele->data = n;
    //将新节点插入到双向链表尾部
    tail->pre->next = new_ele;
    new_ele->next = tail;
    new_ele->pre = tail->pre;
    tail->pre = new_ele;

    size++;//元素个数加1
}

void QUEUE::dequeue()
{
    if (isempty())//避开对空队列的操作
    {
        cout << "queue is empty" << endl;
        return;
    }
    //获取删除将要删除的元素指针
    NODE *temp = front->next;
    front->next = temp->next;
    temp->next->pre = front;
    delete(temp);//释放内存
    size--;
}   

int QUEUE::get_front()
{
    if (front->next != tail)
        return front->next->data;
    else
        cout << "empty queque" << endl;
    return -1;
}

void QUEUE::clear()
{
    NODE *temp = front;
    //遍历链表释放所有节点内存
    while(temp != tail)
    {
        NODE *del_data = temp;
        temp = temp->next;
        delete(del_data);
    }
    //调用函数重新初始化
    initialize();
}

int QUEUE::get_size()
{
    return size;
}

void QUEUE::display_queue()
{
    NODE *temp = front->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    if (isempty())
        cout << "queue is empty" << endl;
    else
        cout << endl;
}

bool QUEUE::isempty()
{
    return front->next == tail;
}

int main(int argc, char const *argv[])
{
    QUEUE que;
    /*
     *do somthing here
     */
    return 0;
}
