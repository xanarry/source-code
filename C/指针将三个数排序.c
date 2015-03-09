#include<stdio.h>
void swap(int *p1, int *p2)
{
	int t;
	t = *p1;
	*p1 = *p2;
	*p2 = t;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) swap(&a,&b);
	if(a>c) swap(&a,&c);
	if(b>c) swap(&b,&c);
	printf("%d %d %d",a,b,c);
	return 0;
}
