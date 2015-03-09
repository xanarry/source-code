#include<stdio.h>
#include<stdlib.h>

//定义qsort中的比较函数 
int cmp(const void * a, const void *b)//const void 是定义比较函数的固定形式 
{
	return ( *(int *)a - *(int *)b );//使用类型强制转换并设定升序还是降序排序 
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
	qsort(a,10,sizeof(int),cmp);//使用qsort给数组排序 
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);
	}
}
