#include<stdio.h>
struct a
{
	int m;
	char n;
}; 
int main()
{
	struct a t;
	t.m = 100;
	t.n = 'M';
	struct a *p = &t;		//���Ͻṹ������ĵ�ַ 
	printf("%d %c",p->m,p->n);
	return 0;
}
