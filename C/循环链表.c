#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE * create(int x);
void display(NODE *head, int x);
int main()
{
	int x;
	NODE *p;
	printf("������ѭ������ڵ�������");
	scanf("%d",&x);
	p = create(x);
	printf("������������ٸ�Ԫ�غ���ֹ�����");
	scanf("%d",&x);
	display(p,x);
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
		printf("�������%d���ڵ�����ݣ�",i);
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

void display(NODE *head, int x)
{
	NODE *p;
	p = head;
	int count = 0;
	while(p != NULL && count != x)
	{
		printf("%d\n",p->data);
		count++;
		p = p->next;
	}
	printf("%d��ѭ������Ľڵ�Ԫ���Ѿ������ϣ�",x);
}
