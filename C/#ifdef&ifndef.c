#include <stdio.h>
#define TEST "this is a test string\n"

int main(int argc, char const *argv[])
{
	#ifdef TEST
		printf(TEST);
	#else
		puts("TEST is not define\n");
	#endif
	#ifndef ABC
		puts("ABC is not define\n");
	#else
		printf(ABC);
	#endif
	return 0;
}
