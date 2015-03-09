#include <stdio.h>
#include <string.h>

int main()
{
	char a[10000][35];
	int i = 0;
	int j=0,k=0,t=0;
	char b[10000][35];
	while (scanf("%s",a[i]) != EOF)
	{
		i++;
	}
	for (j=k;j<i;j++)
	{
		k=strlen(a[j])-4;
		if (a[j][k]=='.' && a[j][k+1]=='e' && a[j][k+2]=='x' && a[j][k+3]=='e')
		{
       	 	strcpy(b[t],a[j]);
       	 	t ++;
		}
	}
	for(i=0; i<t; i++)
	printf("%s\n",b[i]);
	return 0;
}
