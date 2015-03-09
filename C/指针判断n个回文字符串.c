#include<stdio.h>
#include<string.h> 
int judge(char *p, int n)
{
	char *p1;
	int flag = 1;
	p1 = p+n-1;
	while(p<p1)
	{
		if(*p != *p1)
		{
			flag = 0;
			break;
		}
		p++;
		p1--;
	}
	return flag;
}

int main()
{
	int i,j,n;
	char a[100];
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%s",a);
		if(judge(a,strlen(a))) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
