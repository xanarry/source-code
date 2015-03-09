#include <stdarg.h>
#include <stdio.h>

int gcd(int m, int n)
{
	if (m % n == 0)
		return n;
	else
		gcd(n, m % n);
}

int main(int argc, char const *argv[])
{
	printf("%d", gcd(24, 19));
	return 0;
}
