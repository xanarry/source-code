#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct HEAPSTRUCT
{
	int max_capacity;
	int size;
	int *elements;
};

HEAPSTRUCT *initialize(int max_capacity);//初始化队列头和最大容量
void distroy(HEAPSTRUCT **head);//将队列完全从内存中清理掉
void make_empty(HEAPSTRUCT *head);//删除队列中的所有元素
void insert(HEAPSTRUCT *head, int n);//向队列插入元素
int delete_minimum(HEAPSTRUCT *head);//删除最小元素
int get_minimum(HEAPSTRUCT *head);//得到最小元素值
bool is_queue_empty(HEAPSTRUCT *head);//是否为空
bool is_queue_full(HEAPSTRUCT *head);//是否对满
void display_queue(HEAPSTRUCT *head);//显示队列元素
void decrease_key(HEAPSTRUCT *head, int i, int new_key);//减小下标i的优先级
int delete_node(HEAPSTRUCT *head, int i);//删除下标i的元素

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	const int N = 10;
	const int MAX_CAPACITY = 100;

	int a[N] = {32,26,65,68,19,31,24,16,21,13};
	HEAPSTRUCT *queue_head = initialize(MAX_CAPACITY);
	for (int i = 0; i < N; i++)
		insert(queue_head, a[i]);
	display_queue(queue_head);

	for (int i = 0; i < 6; i++)
	{
		cout << "min = " << delete_minimum(queue_head) << endl << endl;
		display_queue(queue_head);
	}

	cout << "delete " << delete_node(queue_head, 2) << endl;
	display_queue(queue_head);
	cout << "decrese " << queue_head->elements[2] << " to " << " 1" << endl;
 	decrease_key(queue_head, 2, 1);
 	display_queue(queue_head);

	return 0;
}

HEAPSTRUCT *initialize(int max_capacity)
{

	HEAPSTRUCT *head = new HEAPSTRUCT();//创建头结点
	head->max_capacity = max_capacity;//设定最大容量
	head->size = 0;//设定当前元素个数
	int *element = new int[max_capacity + 1];//申请储存元素的内存
	head->elements = element;
	return head;
}

void insert(HEAPSTRUCT *head, int n)
{
	/*
	 *将元素插入到队列尾部，然后在循环通过与跟
	 *元素交换位置将新插入的元素向上移动到满足
	 *堆性质的位置
	 */

	//////////////检查可插入性_start
	if (head == NULL)
	{
		cout << "no head find" << endl;
		return;
	}

	if (head->size + 1 > head->max_capacity)
	{
		cout << "error! memery overflow, insert " << n << " failed!" << endl;
		return;
	}
	//////////////检查可插入性_end

	int pos = ++head->size;//长度加1
	head->elements[pos] = n;//将新元素放到列表尾部
	if (pos != 1)//如果插入的不是第一个元素，那么可能需要调整为主
	{
		//当新元素的值比其跟元素的值更小时
		while (head->elements[pos] < head->elements[pos / 2] && pos != 1)
		{
			//将新元素与跟元素不断迭代交换位置，直到找到合适位置
			int temp = head->elements[pos];
			head->elements[pos] = head->elements[pos / 2];
			head->elements[pos / 2] = temp;

			pos = pos / 2;//实现迭代
		}
	}
}

int delete_minimum(HEAPSTRUCT *head)
{
	//第一元素为最小的元素，直接调用delete_node(head, 1)即可
	return delete_node(head, 1);
}

void decrease_key(HEAPSTRUCT *head, int i, int new_key)
{
	if (i >= head->size)
	{
		cout << "the key is not in the queue" << endl;
		return;
	}
	else
	{
		if (new_key >= head->elements[i])
		{
			cout << "new key must greater than the elder key" << endl;
			return;
		}
		else
		{
			//删除旧元素
			delete_node(head, i);、
			//插入新元素
			insert(head, new_key);
		}
	}
}

int delete_node(HEAPSTRUCT *head, int i)
{
	/*找到最小的子元素，将最小子元素移动到跟节点位置，
	 *直到移动到最底部的元素，然后将队列尾部元素移动
	 *到刚移走的底部位置，再将刚删除的元素移动到队列
	 *尾部，这样可以实现排序，但这个操作不是必须的，
	 *可以省略不要
	 */

	if (head->size <= 0)
	{
		cout << "underflow" << endl;
		return -1;
	}
	int min = head->elements[i];
	int root = i;

	//当没有移动到底部元素时，不断迭代
	while (root * 2 <= head->size)
	{
		int child_l = root * 2;
		int child_r = child_l + 1;
		int index_of_min;

		//找到两个子节点中的最小元素
		if (child_l < head->size)
			index_of_min = (head->elements[child_l] > head->elements[child_r] ? child_r : child_l);
		else if (child_l == head->size)
			index_of_min = child_l;

		//向上移动最小的那个元素
		head->elements[root] = head->elements[index_of_min];
		root = index_of_min;//重设跟为刚移动的子元素的位置，实现循环迭代
	}

	//将队列尾部元素，移动到上面循环刚移走的底部元素的位置(非常重要，不然堆结构的性质在以上操作中会被破坏)
	head->elements[root] = head->elements[head->size];
	//将删除的元素移动到队列尾部(非必要，可以不要这一句)
	head->elements[head->size] = min;
	//元素个数减1个
	head->size--;

	return min;
}

void display_queue(HEAPSTRUCT *head)
{
	for (int i = 1; i <= head->size; i++)
		cout << head->elements[i] << " ";
	cout << endl;
}

bool is_queue_full(HEAPSTRUCT *head)
{
	return head->size == head->max_capacity;
}

bool is_queue_empty(HEAPSTRUCT *head)
{
	return head->size == 0;
}

void make_empty(HEAPSTRUCT *head)
{
	head->size = 0;
	delete(head->elements);
}

int get_minimum(HEAPSTRUCT *head)
{
	return head->elements[1];
}

void distroy(HEAPSTRUCT **head)
{
	make_empty(*head);
	free(*head);
}