#include <iostream>
using namespace std;

struct Node//节点结构体
{
	int n;
	Node *next;
};

void Insert(Node *H, int n);//有序插入节点函数
void Show(Node *H);//输出链表

int main(int argc, char const *argv[])
{
	int n;
	Node *HeadPointer;//定义头指针
	Node *HeadNode = new Node;//开辟头节点

	HeadPointer = HeadNode;//头指针指向头节点
	HeadNode->next = NULL;//头节点的下一个位置为空

	for (int i = 0; i < 10; i++)
	{
		cout << "input " << i+1 << "th num" << endl;
		cin >> n;
		Insert(HeadNode, n);//依次插入10个节点
	}
	Show(HeadPointer);//输入构造的有序链表
	return 0;
}

void Insert(Node *H, int n)//传递头节点指针和将要插入的元素
{
	Node *pre = H;//pre为传递过来的头节点的指针
	Node *cur = H->next;//cur表示当前位置，

	Node *_new = new Node;
	_new->n = n;//建立新的节点

	while (cur && n > cur->n)//如果链表不为空，且输入的元素比当前元素大
	{
		pre = cur;
		cur = cur->next;//循环得到中断位置的指针
	}

	_new->next = cur;
	pre->next = _new;//将新节点插入中断位置
}

void Show(Node *H)
{
	Node *p = H->next;//由于头节点数据区没有具体元素，所有输出时跳过头结点
	while (p)
	{
		cout << p->n << " ";
		p = p->next;
	}
}
