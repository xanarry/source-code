#include<stdio.h> 
int main()
{
	int a[2][3]={{1,2,3}, {4,5,6}};   	//定义一个2x3的数组并且赋值 
	int b[3][2], i, j;					//定义一个3x2的数组接受转换后的数组	
	printf("array a:\n");
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 3; j++)			
	   	{
	   		printf("%5d", a[i][j]);		
	    	b[j][i] = a[i][j];			//在输出元素组的同时，转换数组并且将其赋给新的数组，（横纵下标交换） 
	    }
	}
	printf("\n");

	printf("array b:\n");
    for(i = 0; i < 3; i++)
	{
	    for(j = 0; j < 2; j++)
	    {
	    	printf("%5d", b[i][j]);		//输出转换后的输出 
	    	printf("\n");
	    }
	}	
	return 0;	   
}
