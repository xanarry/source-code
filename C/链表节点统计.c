#include <stdio.h>
#include <stdlib.h> 

struct node
{
	int num;
	struct node *next;
};

struct node* creat();	
int node_num(struct node*);
void print(struct node*);
struct node * rm(struct node *r,int x);
int main()
{
	struct node *r,*r1;
	int n;
	int del;
	int i=1;
	r = creat();
	printf("\n链表中的元素是:\n");
	print(r);
	printf("\n链表中的节点个数是:");
	n = node_num(r); 
	printf("%d",n);
}

struct node* creat()
{
	struct node *in;
	struct node *pre;
	struct node *p;
	struct node *head = NULL;
	struct node *r;
	int i = 1;
	int n;
	while(1)
	{
		in = (struct node *)malloc(sizeof(struct node));
		printf("请输入%d个数字 <'0'退出>:",i++);
		scanf("%d",&n);
		if(n == 0) break;
		in->num = n;
		in->next = NULL;
		if(head == NULL)
			head = in;
		else 
			pre->next = in;
		pre = in;	
	}
	return head;
}

void print(struct node *r)
{
	while(r != NULL)
	{
		printf("%d ",r->num);
		r = r->next;
	}
}

int node_num(struct node *r)
{
	int i=0;
	while(r != NULL)
	{
		i ++;
		r = r->next;
	}
	return i;
}
