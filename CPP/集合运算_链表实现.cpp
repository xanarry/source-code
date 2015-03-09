#include <iostream>

using namespace std;

struct Node//表示链表节点的结构体
{
	int num;
	Node *next;
};


void show(Node *);//声明函数输出链表
bool _find(Node *, int);//声明查找函数
Node * create_linklist(int);//声明函数创建集合
Node * Jiao(Node *, Node *);//声明函数求交集
Node * Bing(Node *, Node *);//声明函数求并集
Node * Cha(Node *, Node *);//声明函数求差集


int main(int argc, char const *argv[])
{
	int m, n;
	Node *a = NULL, *b = NULL;//原始集合
	Node *jiao = NULL, *bing = NULL, *cha = NULL;//分别记录返回的交集，并集，差集

	cout << "请分别输入两个集合的元素个数" << endl;
	cin >> m >> n;//m,m表示两个集合元素分别有m,n个

	///注意：在输入集合元素的时候要保证集合中没有相同的元素，因为没有写筛选函数
	a = create_linklist(m);//
	b = create_linklist(n);//

	jiao = Jiao(a, b);//求交集
	show(jiao);//

	bing = Bing(a, b);//求并集
	show(bing);//

	cha = Cha(a, b);//求差集
	show(cha);//
	
	return 0;
}


void show(Node *h)//定义输出链表函数
{
	Node *cur = h;
	if(cur == NULL)
		cout << "Empty";//如果链表为空,即集合为空集，输入empty
	else
	{
		while (cur != NULL)
		{
			cout << cur->num << " ";//遍历输出节点
			cur = cur->next;
		}
	}
	cout << endl;//输出换行
}


bool _find(Node *h, int n)//定义查找函数
{
	Node *head = h;
	while (head)
	{
		if (n == head->num)
			return true;//如果在指定数组中查找到了目标元素，返回TRUE
		head = head->next;
	} 
	return false;//没如有查找到返回FALSE
}


Node * create_linklist(int len)//定义创建集合函数
{
	Node *head = NULL;//创建新的头节点用于返回表示集合的链表
	Node *cur, *pre;//定义上指向一个节点和当前节点的指针
	for (int i = 0; i < len; i++)//循环创建len个节点长构成链表
	{
		Node *cur = new Node;//创建新的节点
		cin >> cur->num;//输入新节点的数据
		cur->next = NULL;//节点末端指向NULL，默认设为终点节点

		if (head == NULL)
			head = cur;//如果头节点为空，那么应该让头结点指向新节点
		else
			pre->next = cur;//否则让上一个节点的next指向新节点
		pre = cur;//上一个节点指针移动到当前位置
	}
	return head;//返回表示集合的链表
}


Node * Jiao(Node *a, Node *b)//定义交集运算函数
{
	Node *r = NULL, *y = b;//r为返回的链表头指针，y用于重置循环中的起点
	Node *pre, cur;//定义上指向一个节点和当前节点的指针
	while (a)//循环a集合
	{
		y = b;//内层循环完后要重置内层循环的起点
		while(y)//循环b集合
		{
			if (a->num == y->num)//如果这个元素两个都有
			{
				Node * _new = new Node;//创建新的节点
				_new->num = a->num;//填充新节点的数据
				_new->next = NULL;//节点末端指向NULL，默认设为终点节点

				if(r == NULL)
					r = _new;//同上
				else
					pre->next = _new;//同上
				pre = _new;//同上
			}
			y = y->next;//移动b集合指针到一下一个节点，实现循环
		}
		a = a->next;//移动a集合指针
	}
	return r;//返回交集
}


Node * Bing(Node *a, Node *b)//定义并集运算函数
{
	Node *r = NULL, *tmp = a;//r为返回的链表头指针，tmp用于循环使用
	Node *cur, *pre;//定义上指向一个节点和当前节点的指针
	while (a)//遍历集合a
	{
		Node * _new = new Node;//创建新的节点
		_new->num = a->num;//填充新节点的数据
		_new->next = NULL;//节点末端指向NULL，默认设为终点节点

		if(r == NULL)
			r = _new;//同上
		else
			pre->next = _new;//同上
		pre = _new;//同上

		a = a->next;//移动指针到下一个节点
	}
	/////以上部分将集合a中的所用元素移动到并集集合中
	while (b)//遍历集合b
	{
		Node *_new = new Node;//创建新的节点
		_new->num = b->num;//填充新节点的数据
		_new->next = NULL;//节点末端指向NULL，默认设为终点节点

		if (!_find(tmp, b->num))//查找只用集合b才有的元素
		{
			pre->next = _new;//同上
			pre = _new;//同上，还是创建链表，接着131行创建的
		}

		b = b->next;//移动指针到下一个节点
	}
	return r;//返回表示并集的链表
}


Node * Cha(Node *a, Node *b)//定义差集运算函数
{
	Node *r = NULL;//r为返回的链表头指针
	Node *cur, *pre;//定义上指向一个节点和当前节点的指针
	while (a)//遍历集合a
	{
		if (!_find(b, a->num))//如果a中的一个元素不同于b中的任何一个元素，那么它肯定是属于差集的
		{
			Node *_new = new Node;//创建新的节点
			_new->num = a->num;//填充新节点的数据
			_new->next = NULL;//节点末端指向NULL，默认设为终点节点

			if (r == NULL)
				r = _new;//同上
			else
				pre->next = _new;//同上
			pre = _new;//同上
		}

		a = a->next;//移动指定到下一个节点
	}
	return r;//返回差集链表
}
