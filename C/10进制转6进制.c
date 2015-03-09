#include <stdio.h>

int main()
{
	int n;
	int t;
	int a[1000];
	int i = 0;
	int j,k;
	int j1;
	scanf("%d",&k);
	for(j1 = 0; j1 < k; j1++)
	{
		scanf("%d",&n);
		i = 0;
		while(n != 0)
		{
			t = n%6;
			a[i++] = t;
			n = n/6;
		}
		for(j = i-1; j >= 0; j--)
		printf("%d",a[j]);
		printf("\n");
	}
	return 0;
}
