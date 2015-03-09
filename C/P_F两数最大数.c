#include<stdio.h>
int max(int *p1, int *p2)
{
	if(*p1 > *p2) return *p1;
	else return *p2;
}
	
int main()
{
	int a,b;
	int *pa,*pb;
	scanf("%d%d", &a,&b);
	printf("%d %d", a,b);
	pa = &a;
	pb = &b;					//取地址 
	printf("\n");
	printf("%d", max(pa,pb));	//用地址作为参数 
	return 0;
}
	
