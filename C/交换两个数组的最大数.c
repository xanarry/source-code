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
	
	printf("����a:");
	for(i = 0; i < N; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	for(i = 0; i < N; i++)
	{
		b[i] = rand()%M;
	}
	
	printf("����b:");
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
	
	printf("����a�����ֵ�ڴ��ַ%p\n����b�����ֵ�ڴ��ַ%p\n",indexa,indexb);
	printf("����a�����ֵ%d\n����b�����ֵ%d\n",*indexa,*indexb);
	*indexb = maxa;
	*indexa = maxb;
	printf("�������������ֵ֮��\n");
	printf("����a:");
	for(i = 0; i < N; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	printf("����b:");
	for(i = 0; i < N; i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
