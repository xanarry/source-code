#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	char input[150];
	char a[70][12];
	int b[70];
	int i;
	int j = 0;
	int k = 0;
	int flag = 1;
	int t = 0;
	gets(input);
	strcat(input,"#");
	for(i = 0; i < strlen(input); i++)
	{
		if( isdigit(input[i]) )
		{	
			a[j][k++] = input[i];
		}
		else
		{
			a[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	for(i = 0; i < j; i++)
	{
		if(strcmp(a[i],"\0") != 0)
			b[t++] = atoi(a[i]);
	}
	qsort(b,t,sizeof(int),cmp);
	for(i = 0; i < t; i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
