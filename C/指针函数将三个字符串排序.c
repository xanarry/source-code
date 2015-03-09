#include <stdio.h>
#include <string.h>
void swap(char *p1, char *p2)
{
	char t[100];
	strcpy(t,p1);
	strcpy(p1,p2);
	strcpy(p2,t);
}
int main()
{
	char a[100];
	char b[100];
	char c[100];
	gets(a);
	gets(b);
	gets(c);
	if(strcmp(a,b) > 0) swap(a,b);
	if(strcmp(a,c) > 0) swap(a,c);
	if(strcmp(b,c) > 0) swap(b,c);
	printf("%s\n%s\n%s",a,b,c);
	return 0;
}
