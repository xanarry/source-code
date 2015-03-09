#include <stdio.h>
#define MIX(a,b) ((a)*(b)+(b))

int main()
{
	int x = 5;
	int y = 10;
	printf("x = 5\ny = 10\n"); 
	printf("x*y+y = %d",MIX(x,y));
	return 0;
}
