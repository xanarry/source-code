#include<stdio.h>
void swap(int *x, int *y)
{
	int t;				//定义临时变量t 
	t= *x;
	*x = *y;
	*y = t;				//交换两指针指向的变量 
}
int main(void)
{
	int a,b,*pa,*pb,t;
	scanf("%d%d",&a,&b);
    swap(&a,&b);		//调用交换函数 
	printf("%d %d",a,b);
}
