#include<stdio.h>
int main()
{   float fn(int);				//声明阶乘函数	
	int n;
	float y;
	printf("输入一个数：");
	scanf("%d",&n);
	if(n>=0)
	{
	    y=fn(n);				//如果输入的n大于0，这调用函数计算阶乘 
      	printf("%d!=%f",n,y);	//输出阶乘结果 
    }
	else printf("n必须大于0\n"); 
}
float fn(int n)
{
	float f;
	if(n==0||n==1) 
		f=1;					//如果n==0 or n==1 则阶乘的值等于1 
    else
		f=fn(n-1)*n;			//递归函数求值 
    return (f);
}
