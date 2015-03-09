#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);//快速排序函数 
}

typedef struct test
{
	int n;
	struct test *next;//构造链表的结构体 
}Node;

int create_node();
Node *head;
int main()
{
	int N;
	N = create_node();//创建链表 
	output_node();
	sort_node(N);//排序 
	output_node();		
}

int create_node()
{
	Node *pre;
	Node *current;
	head = NULL;
	int i = 1; 
	while(1)
	{
		current = (Node *)malloc(sizeof(Node));
		current->next = NULL;
		printf("请输入第%d个节点的元素 <q退出>：",i++);
		scanf("%d",&current->n);
		if(current->n == -1)
			break;
		current->next = NULL;
		if(head == NULL)
			head = current;
		else
			pre->next = current;
		pre = current;
		system("cls");
	}
	return i-2;//i的计数比实际链表元素个数多2，所有减去2； 
}

output_node()
{
	Node *p;
	p = head;
	while(p != NULL)
	{
		printf("%d ",p->n);//遍历输出链表 
		p = p->next;
	}
}

sort_node(int x)
{
	Node *p;
	int a[x];
	int i = 0;
	p = head;
	while(p != NULL)
	{
		a[i] = p->n;//将链表中的数据传递给一维数组 
		i++;
		p = p->next;
	}
	qsort(a,x,sizeof(int),cmp);//对数组快速排序 
	p = head;
	i = 0;
	while(p != NULL)
	{
		p->n = a[i];//将有序数组中的元素还给链表 
		i++;
		p = p->next;
	}
}


