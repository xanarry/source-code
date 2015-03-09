#include<stdio.h>

int main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int *p[10];
	int i;
	int **pt;
	for(i=0;i<10;i++)
	{
		p[i]=&a[i];
	}
	pt=p;
	for(i=9;i>=0;i--)
	printf("%d ",*(*pt+i));
	return 0;
}
