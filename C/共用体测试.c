#include <stdio.h>

union test
{
	int i;
	char c;
};

int main()
{
	union test a;
	puts("����һ��������Ĳ���");
	a.i = 100;
	printf("%d\n",a.i);
	printf("%c\n",a.c);
	a.c = 'A';
	puts("-----------");
	printf("%d\n",a.i);
	printf("%c",a.c);//��Ϊ����һ���ڴ棬����%d��ӦascII�룬%c��Ӧ��Ӧ���ַ� 
	return 0;
}
