#include <stdio.h>
#define test "this is an example\n"

int main()
{
	printf(test);
	#undef test
	printf("test");
	return 0;
}
