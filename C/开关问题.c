#include <stdio.h>

int main()
{
	int n,m;
	int a[10001] = {0};
	int i;
	int j;
	scanf("%d%d",&n,&m);
	for(i = 1; i <= m; i++)
	{
		scanf("%d",&j);
		a[j] = 1 - a[j];
	}
	for(i = 1; i <= n; i++)
	{
		if(a[i] == 1)
		printf("%d ",i);
	}
	return 0;
}
