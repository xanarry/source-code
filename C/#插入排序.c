#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main()
{
	srand(time(NULL));
	int a[N];
	int i;
	int k;
	int j;
	for(i = 0; i < N; i++)
	{
		a[i] = rand()%50 + 1;
	}

	for(i = 1; i < N; i++)
	{
		k = a[i];//��ȡ�Ѿ������Ԫ�غ���ĵ�һ��Ԫ�� 
		j = i-1; //�Ѿ�����õ�Ԫ�ص����һ��Ԫ�ص��±�
		while(a[j] > k && j >= 0)
		{//�����Ԫ�ر��ź�������һ����С���ͺ���Ԫ�أ�֪�����������е�����������С������Ҫ��
			a[j+1] = a[j];
			j--;//����Ԫ�� 
		}
		a[j+1] = k;//����Ԫ�ص�����ͨ��ѭ���ҵ���λ��
	}
		
	for(i = 0; i < N; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
