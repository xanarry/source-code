//使用数组输出斐波那契数列
#include<stdio.h>
void main()
{
	int a[50],i;
	a[0]=1;							
	a[1]=1;							//将a[0],a[0]赋初值为1
	printf("%d\n%d\n",a[0],a[1]);
	for(i=2;i<=30;i++)
	{
		a[i]=a[i-2]+a[i-1];			//从a[2]及第三个数开始，满足当前项的值等于前两项之和
		printf("%d\n",a[i]);
     	}
}  
