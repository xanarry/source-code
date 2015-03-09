#include <stdio.h>
#define N 50

int main()
{
	int i = 50;
	#if N > 50
	i++;
	#endif
	#if N == 50
	i += 50;
	#endif
	#if N < 50
	i--;
	#endif
	printf("now i = %d",i);
	return 0;
}
