#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node//链表节点
{   
    int data;
    Node *next;
};

struct Hash_t//hash结构体
{
    int size;//关键字数量, 为给定最大值的下一个素数
    Node **lists;//存放链表数组的数组起始位置
};

int next_prime(int n)
{
    //计算下一个素数
    if (n < 2)
        return 2;
    while (true)
    {
        bool flag = true;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return n;
        n++;
    }
}

Hash_t *init_hash(int max_size)
{
    //初始化hash表
    Hash_t *hash_table = new Hash_t();
    hash_table->size = next_prime(max_size);//设定最大关键字数量
    hash_table->lists = new Node*[max_size];//申请链表数组空间
    //为没个关键词开辟链表起点
    for (int i = 0; i < max_size; i++)
    {
        hash_table->lists[i] = new Node();
        hash_table->lists[i]->next = NULL;
    }
    return hash_table;
}

int cal_hash_code(int n, int table_size)
{
    //hash函数
    int code = 0;
    while (n > 0)
    {
        code = (code << 5) + n % 10;
        n /= 10;
    }
    return code % table_size;
}

void insert(Hash_t *hash_table, int n)
{
    //向hash表中插入数据
    int hash_code = cal_hash_code(n, hash_table->size);//获取hash值
    //将元素放到新节点中
    Node *new_node = new Node();
    new_node->data = n;
    //头插法插入对应的链表中
    new_node->next = hash_table->lists[hash_code]->next;
    hash_table->lists[hash_code]->next = new_node;
}

Node *search(Hash_t *hash_table, int n)
{
    //搜索元素
    int hash_code = cal_hash_code(n, hash_table->size);
    //首先检查hash值是否存在
    if (hash_table->lists[hash_code]->next == NULL)
        return NULL;
    else//存在hash值的话则搜索链表
    {
        Node *temp = hash_table->lists[hash_code]->next;
        while (temp && temp->data != n)
            temp = temp->next;
        return temp;
    }
}

void disply_hash_table(Hash_t *hash_table)
{
    //输出hash表
    for (int i = 0; i < hash_table->size; i++)
    {
        Node *temp = hash_table->lists[i]->next;
        cout << i << ": [";
        while (temp)
        {
            cout << temp->data << ",";
            temp = temp->next;
        }
        cout << "]" << endl;
    }
}

int main(int argc, char const *argv[])
{   
    int max_size = 20;
    Hash_t *hash_table = init_hash(next_prime(max_size));
    for (int i = 20; i < 40; i++)
        insert(hash_table, i);

    disply_hash_table(hash_table);
    int n = 99;
    for (int i = 10; i < 30; i++)
    {
        Node *res = search(hash_table, i);
        if (res)
            cout << i << " map to: " << res->data << endl;
        else
            cout << i << " map to: NULL" << endl;
    }
    return 0;
}