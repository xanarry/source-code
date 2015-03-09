#include <stdio.h>
#include <stdlib.h>

struct note
{
	int data;
	struct note *next;
};
struct note* create(int a[], int n)
{
	struct note *p;
	struct note *c;
	struct note *head = NULL;
	int i;
	for (i = 0; i < n; i ++)
	{
		c = (struct note *)malloc(sizeof (struct note));
		c->next = NULL;
		c->data = a[i]; 
		if (head == NULL)
			head = c;
		else 
			p->next = c;
		p = c;
	}
	return head;
}
void output(struct note * tou)
{
	while(tou != NULL)
	{
		printf ("%d\n",tou->data);
		tou = tou->next;
	}
}
void fr(struct note *p)
{
	while (p == NULL)
	{
		free(p);
		p = p->next;
	}
}
int main()
{
	struct note *h;
	int a[100];
	int n;
	int i;
	printf("请输入数组的大小，下标的值将作为数组元素输出：");
	scanf ("%d",&n);
	for (i = 0; i < n; i++)
	{
		a[i] = i+1;
	}
	h = create (a,n);
	output (h);
	fr(h);
	return 0;
}
