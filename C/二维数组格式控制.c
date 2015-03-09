#include<stdio.h>
int main()
{
	int i,j,a[3][3]={1,2,3,4,5,6,7,8,9};
	printf("the array is:\n");
	for(i=0;i<3;i++)
    {
    	for(j=0;j<3;j++)
    	{
    		printf("%d ",a[i][j]);	//两个数之间用空格隔开 
    	}
	 	printf("\n");				//输出一行后换行 
    }
  	return 0;
}

