#include<stdio.h>
#define N 3
int main()
{
	int a[N][N];
	int i;
	int j;
	int sum = 0;
	for(i = 0; i < N; i++)
	{
		for(j =0 ; j < N; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}				//����һ������ 
	
	for(j = 0; j < N; j++)
	{
		sum += (a[0][j] + a[N-1][j]);
	}
					//�����һ�к����һ������ 
	for(i = 1; i < N-1; i++)
	{
		sum += (a[i][0] + a[i][N-1]);
	}
					//�����һ�к����һ������ 
	printf("%d",sum);
}
