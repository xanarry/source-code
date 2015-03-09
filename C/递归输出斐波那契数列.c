#include<stdio.h>
int fib(int x)
{
	if(x == 1 || x == 2) return 1;
	return fib(x-1) + fib(x-2);
}
int main(void)
{
    int n;
    for(n = 1;n <= 20; n++)
    { 
		printf("%d\n",fib(n));
	}
	return 0; 
}
