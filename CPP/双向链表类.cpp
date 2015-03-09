#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
	Node *pre;
	int data;
	Node *next;
};

class LinkList
{
private:
	Node *head;
	Node *tail;
	int node_num;
public:
	LinkList()
	{
		head = NULL;
		tail = NULL;
		node_num = 0;
	}
	LinkList(Node * h, Node *t)
	{
		head = h;
		tail = t;
		head->next = tail;
		tail->pre = head;
		node_num = 0;
	}
	~LinkList(){};
	int get_nodes_num();
	void insert_one_node(int n);
	void show_from_begin_to_end();
	void show_from_end_to_begin();
};

int LinkList::get_nodes_num()
{
	return node_num;
}

void LinkList::insert_one_node(int n)
{
	Node *cur = new Node;
	cur->data = n;

	head->next->pre = cur;
	cur->pre = head;

	cur->next = head->next;
	head->next = cur;

	node_num++;
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

void LinkList::show_from_end_to_begin()
{
	Node *p = tail->pre;
	while (p != head)
	{
		cout << p->data << " ";
		p = p->pre;
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

	LinkList List(head, tail);

	int count = 0;
	int value;
	cout << "please input the number of nodes: ";
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		cin >> value;
		List.insert_one_node(value);
	}

	cout << "This LinkList totally have " << List.get_nodes_num() << " nodes!" << endl;
	cout << "show_from_begin_to_end: ";
	List.show_from_begin_to_end();
	cout << endl << "show_from_end_to_begin: ";
	List.show_from_end_to_begin();
	cout << endl;
	return 0;
}
