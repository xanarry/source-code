#include <stdio.h>
#define N 30

int main(int argc, char *argv[])
{
	#if N >= 90
		printf("A\n");
	#elif N >= 80
		printf("B\n");
	#elif N >= 70
		printf("C\n");
	#elif N >= 60
		printf("D\n");
	#else
		printf("E\n");
	#endif
	return 0;
}
