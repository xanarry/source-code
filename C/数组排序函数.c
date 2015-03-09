#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
	int i,a[10];
	for(i = 0;i < 10; i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,10,sizeof(int),cmp); //使用快速排序 
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
