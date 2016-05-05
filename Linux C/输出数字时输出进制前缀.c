#include <stdio.h>
int main()
{
	int a = 12;
	//在数字的格式控制符后面加上一个#号, 可输出进制的前缀, 方便人看
	printf("dec %d %#d\n", a, a);
	printf("oct %o %#o\n", a, a);
	printf("hex %x %#x\n", a, a);
	return 0;
}
