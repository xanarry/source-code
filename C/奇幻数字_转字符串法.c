#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int include(int x,int y)
{
	char a[100];
	char b[100];
	itoa(x,a,10);
	itoa(y,b,10);//将数字转换为支付串，再有字符串中的函数作比较 
	if(strstr(a,b)) 
	return 1;
}
int main()
{
	int m,n;
	int i,sum=0,t;
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++)
	{
		t=i;
		if(t%m==0 || include(i,m))
		sum++;
	}
	printf("%d",sum);
	return 0;
}
