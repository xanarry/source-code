#include<stdio.h>
int main()
{
	int a[3][3];						//���������С 
	int i,j;
	int *p = a;							//��������ָ��ָ������a 
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j ++)
		{
			scanf("%d",(*(a+i) + j));	//*(a+i)��ͬ��a[i],��ʾ�У�j��ʾ�� 
		}
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3;)
		{
			printf("%d ", *( *(a+i) + (j++)));
		}								//ͬ11��ע�� 
		printf("\n");
	}
	return 0;
}
