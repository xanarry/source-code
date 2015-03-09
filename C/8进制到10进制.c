#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int n;
	int sum = 0;
	int t,i;
	int len;
	char in[5];
	gets(in);
	len = strlen(in);
	for(i = (len - 1), t = 0; i >=0; i--)
	{
		sum	+= (in[i]-48)*(pow(8,t++));
	}
	printf("%d",sum);
	return 0;
}
