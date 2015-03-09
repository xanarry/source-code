#include<stdio.h>

int main()
{
	char **p;
	char *a[]={"good","bad","terrible","nice","abc","abont"};
	int i;
	p=a;
	for(i=0;i<6;i++)
	
	{
		printf("%s\n",*(p+i));
	}
	
}
