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
	while((*(to++) = *(from++)) != '\0')//将第二个字符串依次复制给第一个，第一个应该比第一个长，不然会越界出错 
	{
		to[i] = '\0';	
	}
}
