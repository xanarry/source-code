#include<stdio.h>
void swap(int *x, int *y)
{
	int t;				//������ʱ����t 
	t= *x;
	*x = *y;
	*y = t;				//������ָ��ָ��ı��� 
}
int main(void)
{
	int a,b,*pa,*pb,t;
	scanf("%d%d",&a,&b);
    swap(&a,&b);		//���ý������� 
	printf("%d %d",a,b);
}
