#include <stdio.h>
#include <string.h>

int main()
{
	char a[10000][35];
	int i = 0;
	int j=0,k=0;
	while (gets(a[i]) != NULL)
	{
		if (!(strcmp(a[i] + strlen(a[i])-4,".exe") ))
		i++;	
		
	}
	for(k=0;k < i; k++)
	{
		printf("%s\n",a[k]);
	}
	return 0;
}
