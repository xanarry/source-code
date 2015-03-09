#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

struct Node//表示双向链表结构体
{
	Node *pre;//前驱
	int data;//数据
	Node *next;//后继
};

class LinkList//链表类定义
{
private:
	Node *head;//头结点
	Node *tail;//尾节点
	int node_num;//节点数量
public:
	LinkList()//默认构造函数
	{
		head = NULL;
		tail = NULL;
		node_num = 0;
	}
	LinkList(Node * h, Node *t)//带参数构造函数
	{
		head = h;
		tail = t;
		head->next = tail;//连接头尾
		tail->pre = head;//连接头尾
		node_num = 0;
	}
	~LinkList(){};
	int get_nodes_num();
	int push(int n);//插入元素，头插法
	int pop();//删除元素。返回删除的值 
	void show_from_begin_to_end();//遍历链表
};

int LinkList::get_nodes_num()
{
	return node_num;
}

int LinkList::push(int n)
{
	Node *cur = new Node;//新节点
	cur->data = n;

	head->next->pre = cur;//之前头结点的后继的前驱应该是cur
	cur->pre = head;//cur的前驱是头结点

	cur->next = head->next;//cur的后继应该指向之前头结点的下一个节点
	head->next = cur;//头结点把当前cur接上

	node_num++;//有效节点数自加1
	return node_num;
}

int LinkList::pop()
{
	if (node_num == 0)
	{
		cout << "have no elements to pop in this LinkList! please check" << endl;
		exit(1);
	}

	int tmp = head->next->data;//提前当前要删除的数据

	head->next->next->pre = head;//前驱指针跳过删除的节点
	head->next = head->next->next;//后继指针跳过删除的节点

	node_num--;//有效节点数减一
	return tmp;
}

void LinkList::show_from_begin_to_end()
{
	Node *p = head->next;
	while (p != tail)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main(int argc, char const *argv[])
{
	Node *head = new Node;
	head->pre = NULL;
	head->next = NULL;

	Node *tail = new Node;
	tail->pre = NULL;
	tail->next = NULL;

	LinkList List(head, tail);//创建链表对象

	int value;
	cin.clear();
	string operation;
	cout << "input \"push number\" to insert a number, \"pop\" to delete one" << endl;
	while (1)
	{
		cin >> operation;
		if (operation == "push")
		{
			cin >> value;
			List.push(value);
			cout << value << " has been pushed into, now has " << List.get_nodes_num() << " elements" << endl;
		}
		else if (operation == "pop")
		{
			cout << List.pop() << " has been poped!, and now is has " << List.get_nodes_num()-1 << "elements." << endl;
		}
		else
			break;
	}
	cout << "\natfer your pop operation:";
	List.show_from_begin_to_end();
	cout << endl;

	return 0;
}
