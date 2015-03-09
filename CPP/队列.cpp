#include <iostream>
using namespace std;

struct Queue
{
	int *tail;//队尾
	int *head;//队头
	int size;//队列长度
};

bool init_queue(Queue &q)
{
	cout << "NOTICE:input the length of the Queue to initialize it" << endl;
	cin >> q.size;//初始化时制定长度
	q.head = q.tail = new int[q.size];//申请内存空间
	if (q.head == NULL)
		return false;//内存失败返回false
	return true;
}

bool is_queue_full(Queue &q)//判断队列是否已经满员
{
	if (q.tail - q.head >= q.size)//即头尾指针之差已经超过了size的大小
		return true;
	return false;
}

bool push(Queue &q, int value)//插入元素函数
{
	/*简单的插入示意图*/
	/*//|////|////|////|////|////|////|/////
		1    2    3    4    5    6  unknown :remarke the location
		--------------------------------
	   	8 <- 7 <- 5 <- 9 <- 2 <- 3          :each elem move ahead
	tmp=head--------------------->    tail  :how to move each element and overwrite fist element
		---------------------------------	
	   	7	 5	  9	   2    3   new_elem    :insert new one to queue
	*///|////|////|////|////|////|//////////

	if (!is_queue_full(q))//如果队列没有满的时候，则直接插入，移动指针
	{
		*q.tail = value;
		q.tail++;
		cout << value << " has been pushed into Queue" << endl;
	}
	else//否则应该将头部元素删除，并且向前移动后面的所有元素，以便新元素的插入
	{
		int gethead = *q.head;//获取底部元素，用于输出状态
		int *tmp = q.head;//定义tmp保护head指针在内存段中的位置不被修改
		while (tmp != q.tail)
		{
			*tmp = *tmp + 1;//前移元素
			tmp++;
		}
		*--tmp = value;//在后面空出的位置插入新元素
		cout << value << " has been pushed into Queue, and " << gethead << " has been poped" << endl;
	}
}

bool pop(Queue &q)
{
	if (q.head == q.tail)//队列为空不执行任何操作
	{
		cout << "Error! Queue is empty" << endl;
		return false;
	}
	q.tail--;//删除元素，实际上就是指针前移，元素本身并没有被删除，新的插入操作会覆盖掉它
	cout << *q.tail << "has been poped" << endl;
	return true;
}

void traversal(Queue &q)
{
	if (q.head == q.tail)//队列为空时不执行操作
	{
		cout << "Queue is empty" << endl;
		return;
	}
	int *tmp = q.head;//定义tmp保护head指针在内存段中的位置不被修改
	while (tmp != q.tail)//遍历队列输出队列元素
	{
		cout << *tmp << " ";
		tmp++;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	Queue q;
	init_queue(q);
	string operation;
	int value;
	cout << "input your operation" << endl;
	while (cin >> operation)
	{	
		if (operation == "push")
		{
			cin >> value;
			push(q, value);
		}
		if (operation == "pop")
			pop(q);
		if (operation == "traversal")
			traversal(q);
	}
	return 0;
}
