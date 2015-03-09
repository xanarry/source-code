#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char input[1501];
	char a[1501][12];
	int i;
	int j = 0;
	int k = 0;
	int sum = 0;
	gets(input);
	strcat(input,"#");
	for(i = 0; i < strlen(input); i++)
	{
		if( !ispunct(input[i]) )
		{	
			a[j][k++] = input[i];
		}
		else
		{
			a[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	for(i = 0; i < j; i++)
	{
		sum += atoi(a[i]);
	}
	printf("%d",sum);
	return 0;
}
