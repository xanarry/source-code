#include<stdio.h>
int main()
{
	int a[3][3],i,j,max;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}     
	max = a[0][0];					//默认数组第一个元素的值是最大 
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j] > max)		//如果查找到一个组大于max，则将其值给max 
			max = a[i][j];
		}
      }
	printf("%d",max);
	return 0;		   
}
