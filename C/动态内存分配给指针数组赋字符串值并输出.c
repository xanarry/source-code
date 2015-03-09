#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *a[3];
	int i;
	for(i=0;i<3;i++)
	{
		a[i]=(char *)malloc(sizeof(char)*30); //为每个字符串分配30个字节的空间
		scanf("%s",a[i]);
	}
	for(i=0;i<3;i++)
	{
		printf("%s\n",a[i]);
		free(a[i]);
	}
	return 0;
}

