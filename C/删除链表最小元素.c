#include <stdio.h>
#include <stdlib.h>

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
	create_node();//创建链表 
	output_node();
	del_min();//删除元素 
	printf("\n");
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
		printf("请输入第%d个节点的元素 <0退出>：",i++);
		scanf("%d",&current->n);
		if(current->n == 0)
			break;
		current->next = NULL;
		if(head == NULL)
			head = current;
		else
			pre->next = current;
		pre = current;
		system("cls");
	} 
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

del_min()
{
	Node *p,*t;
	Node *index;
	int min;
	if(head == NULL)
	{
		printf("NO DATA IN NODES!\n");
		exit(0);
	}
	
	p = head;
	min = p->n;
	index = p;
	while(p)
	{
		if(min > p->n)
		{
			min = p->n;
			index = p;//查找最小元素及其节点内存地址 
		}
		p = p->next;
	}
	
	p = head;//返回头指针 
	while(p != index)
	{
		t = p;
		p = p->next;
	}
	t->next = p->next;//删除标记节点 
}


