#include <stdio.h>
#define N 50

int main()
{
	int i = 50;
	#if N > 50
		i++;
	#else
		#if N < 50
			i--;
		#else
			i += 50;
		#endif
	#endif
	printf("now i = %d",i);
	return 0;
}
