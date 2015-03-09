#include <stdio.h>
#include <stdlib.h>
#include <string.h>

cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int i,k = 0;
	char str[101];
	int a[100];
	char *p;
	while(scanf("%s",str) != EOF)
	{
		p = strtok(str,",*.+=;!");
		while(p)
		{
			a[k++] = atoi(p);
			p = strtok(NULL,",.+=;!");
		}
		qsort(a,k,sizeof(int),cmp);
		for(i = 0; i < k; i++)
		{
			printf("%d ",a[i]);
		}
		k = 0;
		printf("\n");
	}
	return 0;
}
