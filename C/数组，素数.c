/*****************
数组筛选法找出素数
*****************/ 
#include<stdio.h>
#define N 10000						//输出200以内的素数 
int main()
{
	int a[N] = {0},i,j;				//将数组所有元素置为0 
	for(i = 2; i < N; i++)			//循环从2开始，因为素数大于2 
	{
		if(a[i] == 0)				//用于提高效率，去掉重复的判断，可去掉 
		{
			for(j = i+1; j < N; j++)//向后查找 
			{
				if(j%i == 0)		
				a[j] = 1;			//标记能被前面素数整除的数 
			}
		}
	}
	for(i = 2; i < N; i++)
	{
		if(a[i] == 0)
		printf("%d ",i);			//输入素数 
	}
	return 0;
}
