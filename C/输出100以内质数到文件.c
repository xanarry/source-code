#include <stdio.h>
#include <math.h>

int prime(int x);
int main()
{
	int i;
	int n;
	FILE *p;
	p = fopen("质数表.txt", "wt+");
	fputs("1-100质数表\n-------\n",p);
	for(i = 2; i <= 100; i++)
	{	
		n = i;
		if( prime(n) == 1 )
		{
			printf("%d\n",n);
			fprintf(p,"%d ",n);
		} 	
	}
	return 0;
}
int prime(int x)
{
	int k;
	for(k = 2; k <= sqrt(x); k++)
	{
		if(x%k == 0)
		return 0;
	}
	return 1;
}
