#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE * create(int x);
void display(NODE *head, int i, int x);
int main()
{
	int x;
	int i;
	NODE *p;
	printf("请输入约瑟夫环节点数量：");
	scanf("%d",&i);
	p = create(i);
	printf("请输入删除报数到多少号的元素：");
	scanf("%d",&x);
	display(p,i,x);
	return 0;
}

NODE * create(int x)
{
	int i;
	NODE *current;
	NODE *pre;
	NODE *head = NULL;
	for(i = 1; i <= x; i++)
	{
		current = (NODE *)malloc(sizeof(NODE));
		printf("请输入第%d个节点的数据：",i);
		scanf("%d",&current->data);
		
		current->next = NULL;
		if(head == NULL)
			head = current;
		else
			pre->next = current;
		pre = current;
	}
	current->next = head;
	return head;
}

void display(NODE *head,int i, int x)
{
	NODE *p;
	NODE *pre;
	p = head;
	int t = 1;
	int count = i;
	while(p != NULL)
	{
		if(t%x == 0)
		{
			printf("%d ",p->data); 
			pre->next = p->next;
			count--; 
		}
		pre = p; 
		p = p->next;
		t++;
		if(count == 1)
			break;
	}
	printf("%d",p->data);
}
