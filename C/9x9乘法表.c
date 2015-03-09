#include<stdio.h>
int main()
{
	int i,j;
	for(i=1;i<=9;i++)						//外层循环用来计第一个乘数 1-9 
	{
		for(j=1;j<=i;j++)					//内层循环用来计第二个乘数，并且只循环 i 次，因为乘法表是三角形的 
		{ 
			printf("%2dx%d=%2d ",i,j,i*j);	//分别输入两个乘数和乘积 
		} 
		printf("\n");						//输出完整的一行后换行 
    }
    return 0; 
 }

