#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p;
	int max;
	int i;
	printf("how many num you wanna in a array\n");
	scanf("%d",&max);
	p=(int *)malloc(max*sizeof(int));
	for(i=0;i<max;i++)
	{
		scanf("%d",p+i);
	}
	for(i=0;i<max;i++)
	{
		printf("%d ",*p+i);
		free(p+i);
	}
	return 0;
}
