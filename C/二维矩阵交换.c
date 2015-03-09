#include<stdio.h>
#define N 3
void move(int p[][N])
{
	int i,j,t;
	for(i = 0; i < N; i++)
	{
		for(j = i; j < N; j++)
		{
			t = p[i][j];
			p[i][j] = p[j][i];
			p[j][i] = t;
		}
	}
}
int main()
{
	int i,j;
	int a[N][N];
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d",&a[i][j]);
		} 
	}
	move(a);
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ",a[i][j]);
		} 
		printf("\n"); 
	}
}
