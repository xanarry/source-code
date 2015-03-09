#include <iostream>
using namespace std;

struct Node//链表节点结构体
{
	int n;//节点数据
	Node *next;//一个结构体指针
};

Node * Create(const int);//声明创建链表的函数
void Conduct(Node *, const int ,const int);//声明筛选结果的函数
void free(Node *);//声明释放内存的函数

int main(int argc, char const *argv[])
{
	int m, n;//定义m表示节点总数，n表示报数是报到的最大数字
	Node *p = NULL;//定义空结构指针
	while (1)
	{
		cout << "请输入猴子个数及报数的最大数字" << endl;
		cin >> m >> n;//输入数据

		if (m == 0)
			return 0;

		p = Create(m);//调用函数创建循环链表

		Conduct(p, m, n);//调用函数筛选猴王
	}

	free(p);
	return 0;
}

Node * Create(const int n)
{
	int i = 1;//定义i计数
	Node *head = NULL;//定义head头指针默认指向null
	Node *previous;//定义表示上一个节点的指针
	Node *current;//定义表示当前节点的指针
	while (i <= n)//循环n次，为每个猴子创建节点
	{
		current = new Node();//开辟新的节点内存空间
		current->n = i;//给每个节点赋值
		if (head == NULL)
			head = current;//如果头节点为空，则应该让头结点指向新开辟的节点地址
		else
			previous->next = current;//如果已经不是第一个节点，就让上一个节点的‘next’指向新的节点，才能串到一块

		previous = current;//再将上一个位置的指针向后移一位，因为上面的操作使链表增长一个节点
		i++;
	}
	current->next = head;//将最后一个节点的‘next’指向头节点，实现链表的循环
	return head;//返回链表头指针个主函数
}

void Conduct(Node *head, const int i, const int x)
{
	Node *p = NULL;//定义临时指针
	Node *previous;//定义表示上一个节点的指针
	p = head;//获取链表入口
	int t = 1;//定义t模拟猴子报数
	int count = i;//定义count表示链表中的有效节点数量
	while(p != NULL)//如果链表不为空，则执行如下操作
	{
		if(t%x == 0)//表示如果这个猴子正好报到尾数，t表示正好报道数，x表示报数的最大值
		{
			previous->next = p->next;//删除表示这个猴子的节点
			count--;//链表中的有效节点减一
		}

		previous = p;//记录当前节点
		p = p->next;//节点继续向后移动

		t++;//报数在增加，是一直在增加的，用求余去实现报数的循环

		if(count == 1)//如果最后只剩下一个有效节点
			break;//终止继续排除节点
	}
	cout << "猴王是" << p->n << "号\n" << endl;//输出最后留下的节点表示猴王
}

void free(Node *t)
{
	Node *p = t;
	while (p != NULL)
	{
		delete(p);//释放节点
		p = p->next;
	}
}
