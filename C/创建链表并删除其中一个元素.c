#include <stdio.h>
#include <stdlib.h> 

struct node
{
	int num;
	struct node *next;
};

struct node* creat();	
void print(struct node*);
struct node * rm(struct node *r,int x);

int main()
{
	struct node *r;
	int n;
	int del;
	int i = 1;
	r = creat();
	printf("\n�����е�Ԫ����:\n");
	print(r);
	printf("\n������Ҫɾ��������Ԫ��:");
	scanf("%d",&del);
	printf("\nɾ����Ԫ����%d\n",del);
	r = rm(r,del);
	print(r);
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
		printf("������%d������ <'0'�˳�>:",i++);
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

struct node * rm(struct node *r,int x)
{
	struct node *p, *pre;
	p = r;
	while(p && (p->num != x))
	{
		pre = p;
		p = p->next;
		
	}
	if(p)
	{
		if(p == r)
			r = p->next;
		else
			pre->next = p->next;
	}
	return r;	
}
