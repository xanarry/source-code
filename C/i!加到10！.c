#include<stdio.h>
int j(int a)
{
	if(a == 1) return 1;
 	else return j(a-1)*a;
}
int main(void)
{
	int n;
	long int sum=0;
	for(n = 1; n <= 10; n++)
	sum += j(n);			//函数j用来计算阶乘 
	printf("%d",sum);
}
