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
	struct a *p = &t;		//赋上结构体变量的地址 
	printf("%d %c",p->m,p->n);
	return 0;
}
