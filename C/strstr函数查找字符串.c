#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	char b[100];
	gets(a);
	gets(b);
	if(strstr(a,b))			//用于查找b是否在a内，会返回0和1 
		printf("string b is included");
	else 
		printf("string b is not included");
	return 0;	
}
