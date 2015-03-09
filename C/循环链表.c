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
	printf("请输入循环链表节点数量：");
	scanf("%d",&x);
	p = create(x);
	printf("请输入输入多少个元素后终止输出：");
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
	printf("%d个循环链表的节点元素已经输出完毕！",x);
}
