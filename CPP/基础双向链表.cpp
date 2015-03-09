#include <iostream>
using namespace std;

struct Node
{
	Node *pre;
	int n;
	Node *next;
};

int main(int argc, char const *argv[])
{
	int n, value;
	cin >> n;

	Node *head = new Node;//创建头结点
	head->next = NULL;
	head->pre = NULL;

	Node *last = head;//last表示当前位置的上一个节点

	for (int i = 0; i < n; ++i)//链接n个节点
	{
		cin >> value;

		Node *_new = new Node;//新建每个新的节点
		_new->n = value;//赋值
		_new->next = NULL;//默认为最后一个节点，处理后不用再额外处理最后一个节点

		if (head->next == NULL)//如果该新节点是出头节点的第一节点
		{
			_new->pre = head;//新节点的前驱指向头节点
			head->next = _new;//头节点的后继指向新节点
		}
		else//如果是后面的普通节点
		{
			last->next = _new;//上一个节点的后继指向新节点
			_new->pre = last;//新节点的前驱指向上一个节点
		}
		last = _new;//表示上一个节点的指针后移到当前节点上
	}

	Node *tmp = head->next;//排除头节点
	Node *tmpa;//记录最后一个数据节点用于逆向输出
	cout << "from begin to end" << endl;
	while (tmp)
	{
		cout << tmp->n << " ";
		tmpa = tmp;//记录最后一个有效节点，切记不能在后面用tmp->pre表示tmpa,应为tmp最后已经为NULL
		tmp = tmp->next; 
	}
	cout << endl;

	cout << "\nfrom end to begin" << endl;
	while (tmpa != head)//排除头节点的无效信息
	{		
		cout << tmpa->n << " ";
		tmpa = tmpa->pre;
	}
	cout << endl << endl;
	return 0;
}
