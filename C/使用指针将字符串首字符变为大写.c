#include <stdio.h>
int main()
{
	int n,i;
	char a[100][100];
	char *p;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%s",a[i]);
		p = &a[i][0];
		*p -= 32;
		printf("%s\n",a[i]);
	}
	return 0;
} 
