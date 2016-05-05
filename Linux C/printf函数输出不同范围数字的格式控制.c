#include <stdio.h>
int main()
{
	unsigned int un = 3000000000; //32bit
	short int end = 200;
	long big = 65537;
	long long verybig = 12345678908642;
	printf("un %u and not %d\n", un, un);
	printf("end %hd and %d\n", end, end);
	printf("big %ld and %hd\n", big, big);
	printf("verybig %lld and not %ld\n", verybig, verybig);
	/*
	不同类型的数据在内存中保存的二进制编码可以一样, 特别是无符号数和有符号数
	因此, 为了得到预期的输出结果, 必须要告诉系统这个东西用什么样的方式解析, 系统才能得到正确的结果
	*/
	return 0;
}
