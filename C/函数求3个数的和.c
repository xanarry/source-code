#include<stdio.h>
int sum(int a, int b, int c)
{
	int n;
  	n = a + b + c;
  	return n;
}								//定义函数计算三个数之和并返回 
int main()
{
  	int x,y,z;
  	printf("输入3个数:");
  	scanf("%d%d%d",&x,&y,&z);
  	printf("%d\n",sum(x,y,z));
  	return 0;
}

