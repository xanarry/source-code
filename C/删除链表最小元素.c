#include <stdio.h>
#include <stdlib.h>

typedef struct test
{
	int n;
	struct test *next;//��������Ľṹ�� 
}Node;

int create_node();
Node *head;
int main()
{
	int N;
	create_node();//�������� 
	output_node();
	del_min();//ɾ��Ԫ�� 
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
		printf("�������%d���ڵ��Ԫ�� <0�˳�>��",i++);
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
		printf("%d ",p->n);//����������� 
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
			index = p;//������СԪ�ؼ���ڵ��ڴ��ַ 
		}
		p = p->next;
	}
	
	p = head;//����ͷָ�� 
	while(p != index)
	{
		t = p;
		p = p->next;
	}
	t->next = p->next;//ɾ����ǽڵ� 
}


