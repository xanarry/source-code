#include <stdio.h>
#include <time.h>
#define N 100000
#define M 1000 
int main()
{
	int a[N];
	int b[N];
	int i;
	int j;
	int *pa;
	int *pb;
	int *indexa;
	int *indexb;
	int maxa;
	int maxb;
	srand(time(NULL)); 
	for(i = 0; i < N; i++)
	{
		a[i] = rand()%M;
	}
	
	printf("数组a:");
	for(i = 0; i < N; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	for(i = 0; i < N; i++)
	{
		b[i] = rand()%M;
	}
	
	printf("数组b:");
	for(i = 0; i < N; i++)
	{
		printf("%d ",b[i]);
	}
	
	printf("\n");
	maxa = *a;
	indexa = a;
	for(pa = a+1; pa < a+N; pa++)
	{
		if(*pa > maxa)
		{
			maxa = *pa;
			indexa = pa;
		}
	}
	maxb = *b;
	indexb = b;
	for(pb = b+1; pb < b+N; pb++)
	{
		if(*pb > maxb)
		{
			maxb = *pb;
			indexb = pb;
		}
	}
	
	printf("数组a的最大值内存地址%p\n数组b的最大值内存地址%p\n",indexa,indexb);
	printf("数组a的最大值%d\n数组b的最大值%d\n",*indexa,*indexb);
	*indexb = maxa;
	*indexa = maxb;
	printf("交换数组中最大值之后：\n");
	printf("数组a:");
	for(i = 0; i < N; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	printf("数组b:");
	for(i = 0; i < N; i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
