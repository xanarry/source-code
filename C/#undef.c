#include <stdio.h>
#define N "this is test\n"

int main()
{
	#ifdef N
		printf(N);
		#undef N
	#endif
	
	#ifdef N
		printf(N);
	#else
		printf("N has been undefine\n");
	#endif
	return 0;
}
