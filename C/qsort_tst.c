#include<stdio.h>
#include<stdlib.h>

//����qsort�еıȽϺ��� 
int cmp(const void * a, const void *b)//const void �Ƕ���ȽϺ����Ĺ̶���ʽ 
{
	return ( *(int *)a - *(int *)b );//ʹ������ǿ��ת�����趨�����ǽ������� 
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
	qsort(a,10,sizeof(int),cmp);//ʹ��qsort���������� 
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);
	}
}
