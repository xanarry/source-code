#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[15];
	char b[300][300];
	char c[5];
	int t = 0;
	while(strcmp(gets(a),"exit") != 0)
	{
		if(a[1] == 'u')
		{
			strcpy(b[t],(a+5));
			t++;
		}
		if(a[1] == 'o')
		{
			puts(b[t - 1]);
			t--;
		}
	}
	return 0;
}
