#include <stdio.h>
int main()
{
	void copy(char *from, char *to);
	char a[]="jkgjgkkjjgjgjhuhgj";
	char b[]="123231224562523";
	printf("string a= %s\nstring b= %s\n\n",a,b);
	copy(b,a);
	printf("string a= %s\nstring b= %s\n",a,b);
	return 0;
}
void copy(char *from, char *to)
{
	int i=0;
	while((*(to++) = *(from++)) != '\0')//���ڶ����ַ������θ��Ƹ���һ������һ��Ӧ�ñȵ�һ��������Ȼ��Խ����� 
	{
		to[i] = '\0';	
	}
}
