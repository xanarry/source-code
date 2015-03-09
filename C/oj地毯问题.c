#include <stdio.h>
#include <stdlib.h>

struct dt
{
	int a;
	int b;
	int g;
	int k;
};

int main()
{
	int n;
	int i;
	int x,y;
	int flag = -100;
	scanf("%d",&n);
	struct dt in[10005];
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d",&in[i].a, &in[i].b, &in[i].g, &in[i].k);
	}
	scanf("%d %d",&x, &y);
	
	for(i = n; i >= 1; i--)
	{
		if(x>=in[i].a && x<=in[i].a+in[i].g && y>=in[i].b && y<=in[i].b+in[i].k)
		{
			flag = i;
			break;
		}
	}
	
	if(flag >= 0)
		printf("%d",flag);
	else
		printf("%d",-1);
	return 0;
}
