#include<stdio.h>

int main()
{
	char *a;
	char *p;
	int i=0;
	char str[100];
	a=str;
	scanf("%s",a);
	p=a;
	while(*p!='\0')
	{
		p++;
		i++;
	}
	printf("%d",i);
	return 0;
} 
