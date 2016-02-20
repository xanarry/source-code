#include <stdio.h>

int main()
{
	int n;
	int t;
	int a[1000];
	int i;
	int to;
	int flag;
	printf("请输入原十进制数:");
	scanf("%d",&n);
	flag = n;
	printf("请输入将要转换的进制:");
	scanf("%d",&to);
	i = 0;
	while(n != 0)
	{
		t = n%to;
		a[i++] = t;
		n = n/to;
	}
	printf("%d的%d进制数是：",flag,to);
	for(n = i - 1; n >= 0; n--)
	{
		printf("%d",a[n]);
	}	
	printf("\n");
	return 0;
}
