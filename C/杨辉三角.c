#include<stdio.h>
int main()
{
	int i, j, a[100][100];						//定义一个最大长度为100的二维数组 
	int n;
	printf("input n=:\n");
	scanf("%d", &n);

	for(i = 1; i < n; i++)
	{
		a[i][1] = 1;
		a[i][i] = 1;							//将二维数组的首行和对角线都赋值为1 
	}

	for(i = 3; i < n; i++)
	{
		for(j = 2; j < i; j++)					//由于是三角形，所以内层只循环i次 
		{
			a[i][j] = a[i-1][j-1] + a[i-1][j];	//对于内层非1的元素，都满足当前项 = 上一列对应的元素 + 上一列左边的元素 
		}
	}

	for(i = 1; i < n; i++)
	{
		for(j = 1; j <= i; j++)
		{ 
    		printf("%-2d ", a[i][j]);			//输出杨辉三角 
    	} 
    	printf("\n");
	}
	return 0; 
 }  
