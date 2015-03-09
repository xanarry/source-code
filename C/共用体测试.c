#include <stdio.h>

union test
{
	int i;
	char c;
};

int main()
{
	union test a;
	puts("这是一个共用体的测试");
	a.i = 100;
	printf("%d\n",a.i);
	printf("%c\n",a.c);
	a.c = 'A';
	puts("-----------");
	printf("%d\n",a.i);
	printf("%c",a.c);//因为共用一段内存，所以%d对应ascII码，%c对应相应的字符 
	return 0;
}
