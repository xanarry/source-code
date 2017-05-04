#include<stdio.h>
#include<stdlib.h>
int cmp(const void * a, const void *b)//const void
{
	return ( *(int *)a - *(int *)b );//
}

int main()
{
	int a[10];
	int i,j;
	printf("input 10 nums:\n");
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[1][i]);
	}
	printf("qosting\n");
	qsort(a,10,sizeof(int),cmp);//
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);
	}
}
