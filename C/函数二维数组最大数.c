int max(int array[][4], int m, int n)//定义函数中的二维数组不能省略第二维的大小 
{
	int x,y,k;
	k=array[0][0];
	for(x = 0; x < m; x++)
	{ 
		for(y = 0; y < n; y++)
	  	{
	  		if(array[x][y] > k)
	  	   	k = array[x][y];    	//遍历 赋值 
	  	}
	} 
	return k;
}
#include<stdio.h>
int main()
{
   int a[3][4] = {{4,56,3,2},{92,32,1,43},{8,769,55,87}};
   printf("%d",max(a,3,4));
   return 0;
}
