#include <iostream>
using namespace std;

struct NODE//定义链表结构
{
    int data;
    NODE *next;   
};

class STACK//定义栈类
{
private:
    NODE *stack;

public:
    STACK();
    ~STACK(){}
    void initialize();//初始化
    void push(int n);
    void pop();
    int get_top();
    void clear();
    bool isempty();
    unsigned size();
    void display_stack();//显示从栈底到栈顶的元素
};

void STACK::initialize()
{
    //初始化头结点
    stack = new NODE();
    stack->data = 0;//设置元素个数为0
    stack->next = NULL;
}

STACK::STACK()
{
    initialize();
}

void STACK::push(int n)
{
    //创建新的节点
    NODE *new_ele = new NODE();
    new_ele->data = n;//插入数据
    //头插法连接到链表中
    new_ele->next = stack->next;
    stack->next = new_ele;
    stack->data++;
}

void STACK::pop()
{
    if (isempty())//检查是否是在空栈中进行操作
    {
        cout << "stack is empty" << endl;
        return;
    }
    NODE *temp = stack->next;
    stack->next = temp->next;
    delete(temp);//释放删除节点的内存
    stack->data--;
}

void STACK::clear()
{
    stack->data = 0;
    stack = stack->next;
    NODE *tmp = NULL;
    //释放所有节点的内存
    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        delete(tmp);
    }
    //调用函数重新初始化
    initialize();
}

bool STACK::isempty()
{
    return stack->data > 0 ? false : true;
}

int STACK::get_top()
{
    if (!isempty())
        return stack->next->data;
    else
        cout << "stack is empty" << endl;
    return -1;
}

void STACK::display_stack()
{
    //输出栈中元素，将栈中元素导出到数组中然后输出，实际中可以忽略次函数
    if (isempty())
    {
        cout << "stack is empty" << endl;
        return;
    }
    int t_size = stack->data;
    int s_size = stack->data;
    int *list = new int[t_size];
    NODE *temp = stack->next;
    while (temp)
    {
        list[--t_size] = temp->data;
        temp = temp->next;
    }
    for (int i = 0; i < s_size; i++)
        cout << list[i] << " ";
    cout << endl;
}

unsigned STACK::size()
{
    return stack->data;
}

int main(int argc, char const *argv[])
{
    STACK stack;
    /*
     *do somthing here
     */
    return 0;
}