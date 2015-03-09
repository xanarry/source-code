#include <stdio.h>
#include <string.h> 
int judge(char *p, int n)
{
	char *p1;
	int flag = 1;
	p1 = p+n-1;
	while(p < p1)
	{
		if(*p != *p1)
		{
			flag = 0;
			break;
		}				//ÅÐ¶ÏÊÇ·ñ»ØÎÄ 
		p++;
		p1--;
	}
	return flag;
}

int main()
{
	char a[50];
	int n;
	gets(a);
	n = strlen(a);
	if(judge(a,n))
		printf("Yes");
	else
		printf("No");
	return 0;
}
