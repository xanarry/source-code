#include<stdio.h>
int main(void)
{
	int n,j,i;
	scanf("%d",&n);
	for(i = 1; i <= n; i++)			//每层循环都有固定规律 
	{
		for(j = 1; j <= n-i; j++)
			printf(" ");			//控制每行的空格 
		for(j = 1; j <= 2*i-1; j++)
			printf("*");			//输出"*" 
		printf("\n");				//输出换行 
	}
	//上面是整个图形的上办部分，下面是下半部分，区别在于最外层循环 
	for(i = n-1; i >= 1; i--)
	{
		for(j = 1; j <= n-i; j++)
			printf(" ");
		for(j = 1; j <= 2*i-1; j++)
			printf("*");
		printf("\n");			
	} 
	return 0; 
}
