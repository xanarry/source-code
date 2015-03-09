#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int n;
	int t;
	int a[1000];
	int i = 0;
	int j;
	scanf("%d",&n);
	while(n != 0)
	{
		t = n%2;
		a[i++] = t;
		printf("%d ",t);
		n = n/2;
	}
	printf("\n\n");
	for(j = i-1; j >= 0; j--)
	printf("%d",a[j]);
	return 0;
}
