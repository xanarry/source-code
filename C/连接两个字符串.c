#include <stdio.h>

int main()
{
	char a[100];
	char b[100];
	char *pa;
	char *pb; 
	printf("input first string\n");
	gets(a);
	printf("input second string\n");
	gets(b);
	pa = a;
	pb = b;
	while(*pa != '\0')
	{
		pa++;
	}
	while(*pb != '\0')
	{
		*pa++ = *pb++;
	}
	*pa = '\0';
	puts(a);
	return 0;
}
