#include <iostream>
using namespace std;

struct Node
{
	Node *pre;//前驱
	int data;//数据区
	Node *next;//后继
};

void Insert(Node * const, int);
void ShowNode(Node *const);

int main(int argc, char const *argv[])
{
	Node *head = new Node;//头节点
	head->next = NULL;//初始化头结点后继
	head->pre = NULL;//初始化头结点前驱
	cout << "please input ctrl+z to break input" << endl;
	int n;
	while (cin >> n)
	{
		Insert(head, n);//调用函数插入节点
	}
	ShowNode(head);
	return 0;
}

void Insert(Node * const head, int n)
{
	Node *last = head;//定义last用于表示当前节点的上一个节点
	Node *cur = new Node;//开辟新节点
	cur->data = n;//填充数据

	if (head->next != NULL)//如果当前节点不是除了头结点的第一个节点
		head->next->pre = cur;//那么头结点后面那个节点的前驱应该指向新的节点

	cur->next = head->next;//新节点的后继，指向头结点的后继
	head->next = cur;//头结点的后继指向当前节点
	cur->pre = head;//当前节点的前驱指向头结点
}

void ShowNode(Node * const head)
{
	Node *p = head->next;//头结点的值是未定义了，排除他
	Node *tail = NULL;
	cout << "from begin to end" << endl;
	while (p)
	{
		cout << p->data << " ";
		tail = p;//记录尾部地址
		p = p->next;//顺序输出
	}

	cout << "\nform end to begin" << endl;
	while (tail != head)//同样排除头结点
	{
		cout << tail->data << " ";
		tail = tail->pre;//反序输出
	}
}
