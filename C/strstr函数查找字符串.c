#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	char b[100];
	gets(a);
	gets(b);
	if(strstr(a,b))			//���ڲ���b�Ƿ���a�ڣ��᷵��0��1 
		printf("string b is included");
	else 
		printf("string b is not included");
	return 0;	
}
