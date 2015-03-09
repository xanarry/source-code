#include<stdio.h>
int main()
{
	int n,i;
 	long long s=1;
 	printf("input n!, n=");
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
 	{ 
    	s=s*i;			//使用循环实现阶乘，每次i自加1，直到 i == n 
	}
 	printf("n!=%d\n",s);
 	return 0;
}
