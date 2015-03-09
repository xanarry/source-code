#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);//���������� 
}

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
	N = create_node();//�������� 
	output_node();
	sort_node(N);//���� 
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
		printf("�������%d���ڵ��Ԫ�� <q�˳�>��",i++);
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
	return i-2;//i�ļ�����ʵ������Ԫ�ظ�����2�����м�ȥ2�� 
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

sort_node(int x)
{
	Node *p;
	int a[x];
	int i = 0;
	p = head;
	while(p != NULL)
	{
		a[i] = p->n;//�������е����ݴ��ݸ�һά���� 
		i++;
		p = p->next;
	}
	qsort(a,x,sizeof(int),cmp);//������������� 
	p = head;
	i = 0;
	while(p != NULL)
	{
		p->n = a[i];//�����������е�Ԫ�ػ������� 
		i++;
		p = p->next;
	}
}


