#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char isbn[13];
	int i;
	int j;
	int sum = 0;
	int t;
	gets(isbn);
	for(i = 0, j = 1; i < 12; i++)
	{
		if( isdigit(isbn[i]) ) 
		{
			sum += (isbn[i] - 48) * j;
			j++;
		}
	}
	t = sum % 11;
	if(t == 10)
	{
		if(isbn[12] == 'X')
		printf("Right");
		else 
		{
			isbn[12] = 'X';
			isbn[13] = '\0';
			printf("%s",isbn);
		}
	}
	else
	{
		if(isbn[12] - 48 == t)
		printf("Right");
		else 
		{
			isbn[12] = t+48;
			isbn[13] = '\0';
			printf("%s",isbn);
		}
	}
	return 0;
}
