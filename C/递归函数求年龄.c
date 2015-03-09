/*已知有a个人，每个人的年龄是前一个人的年龄+2，而最后一个人的年龄是10，求a的年龄*/ 
#include<stdio.h>

int age(int n)
{
	int c;
	if(n==1)
		c=10;			//当查找到第一个人时，年龄是1 
	else 
		c=age(n-1)+2;	//其他每个人的年龄都遵循这个递归原则 ，不断调用函数本身 
	return c;
}

int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",age(a));
}
