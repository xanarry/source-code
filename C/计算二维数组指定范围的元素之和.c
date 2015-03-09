#include<stdio.h>
int main(void)
{
	int  a[500][500];
	long long sum = 0;
	int m,n;							//定义数组的长和宽 
	int p;								//表示每个元素的访问次数 
	int i,j;
	int x1,y1;							//记录起始坐标 
	int x2,y2;							//记录结束坐标	
	scanf("%d %d %d",&m,&n,&p);			//输入要计算的数组长宽，及范围内没个元素的访问次数p 
	
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d",&a[i][j]);		//填充数组元素 
		}
	}
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);	//输入始末坐标 
	
	if(x1 == x2)
	{
		for(j = y1; j <= y2; j++)
		{
			sum += a[x1][j];
		}
	}
	
	else
	{
		for(j = y1; j <= n; j++)
		{
			sum += a[x1][j];
		}								//单独计算第一行数据,从y1到n列 
	
		for(i = x1+1; i <= x2-1; i++)
		{
			for(j = y1; j <= n; j++)
			{
				sum += a[i][j];			//将x2前面的所有列全部相加 
			}
		}
	
		for(j = 1; j <= y2; j++)
		{
			sum += a[x2][j];			//单独计算最后一行，从1到y2列，因为坐标可能没在末尾 
		}
	}

	printf("%lld",sum*p);				//将单次求和结果乘以访问次数，输出结果 
	return 0;
}
