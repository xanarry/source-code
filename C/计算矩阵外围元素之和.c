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
	}				//接收一个矩阵 
	
	for(j = 0; j < N; j++)
	{
		sum += (a[0][j] + a[N-1][j]);
	}
					//计算第一行和最后一行数据 
	for(i = 1; i < N-1; i++)
	{
		sum += (a[i][0] + a[i][N-1]);
	}
					//计算第一列和最后一列数据 
	printf("%d",sum);
}
