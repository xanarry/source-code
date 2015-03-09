#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char a[100];
	int i;
	int s=0;
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(isalpha(a[i])&&(a[i+1]==' '||a[i+1]=='\0'||ispunct(a[i+1])))
		s++;
	} 
	printf("%d",s);
	return 0;
}
