#include <stdio.h>

int max=0;
int a[30][30];
int n;
void dfs(int x, int y, int sum)
{
	if (x < n && y < n)
	{
		dfs (x + 1, y, sum + a[x][y]);
		dfs (x + 1, y + 1, sum + a[x][y]);
	}
	else if (sum > max)
		max = sum;
}
int main()
{
	int i,j;
	scanf ("%d",&n);
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			scanf ("%d",&a[i][j]);
	dfs (0,0,0);
	printf("%d", max);
} 
