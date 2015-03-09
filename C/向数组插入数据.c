#include<stdio.h>
int main()
{
	int i,a[100],b[100],n,num,m;
	printf("input how many nums in array\n");
	scanf("%d",&m);
	printf("input %d nums\n",m);
	for(i = 0; i < m; i++)
	{
		scanf("%d",&a[i]);				//输入原数组 
	}
	printf("array you input is:\n");  
	for(i = 0; i < m; i++)
	{
		printf("%d ",a[i]);				//输出原数组 
	} 
	printf("\n-----------------------------------------\n");
	printf("请输入插入的位置和数\n");
	scanf("%d %d",&n,&num);				//接收插入的位置和数 
	printf("you'll insert %d to %dth\n",num,n);
	for(i = 0;i < n-1; i++)
	{
		b[i] = a[i];					//将插入位置前面的数不变赋给新的数组 
	} 
	b[n-1] = num;						//在指定位置插入数字 
	for(i = n; i < m+1; i++)
	{ 
		b[i] = a[i-1];					//将插入位置后面的数向后移 ，同事给新的数组 
	} 
	for(i = 0;i < m+1; i++)
	{
		printf("%d ",b[i]);				//输出插入元素的数组 
	}
	return 0;
}	    
