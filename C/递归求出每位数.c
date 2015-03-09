#include<stdio.h>
int function(int n)
{
	if(n < 10) 					//当n为一位数的时候
	printf("%d",n);				//直接输出它 
	else						//如果不是一位数 
	{
		function(n/10);			//将其取整 
		if(n != 0) 
		printf(" %d", n%10);	//输入取整后的余数实现分离							 
	}
}								//8 10行交换就反序输出
int main()
{
	int x;
	scanf("%d", &x); 
	function(x);				//调用函数 
	return 0;
}
