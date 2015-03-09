#include <stdio.h>
#include <stdlib.h>

int separation(int n)
{	
	int temp;
	temp = n/10;
	if (temp > 0)
		separation(temp);
	printf("%d\n", n%10);	
}

int main(int argc, char const *argv[])
{
	printf("input a integer:");
	int num;
	scanf("%d", &num);
	separation(num);
	return 0;
}