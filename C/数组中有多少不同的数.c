#include<stdio.h>
int main()
{
	int a[10], i, j, d = 1;
	
	printf("input 10 nums\n");
	scanf("%d", &a[0]);			//�������յ�һ�� 
	for(i = 1; i<10; i++,d++)	//ÿ����һ������d��1 
	{
		scanf("%d", &a[i]);
		for(j = 0; j < i; j++)
		{
			if(a[i] == a[j])
			{
				d--;
				break; 			//������ǰ����ѽ��ܵ�����ͬ��d��1 
			}
		}
	}
	printf("%d\n", d);
}

