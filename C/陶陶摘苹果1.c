#include<stdio.h>
int main()
{
	int a[10],height,i,count=0;
	const int chair=30;				//等同于define 
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);			//输入每个苹果的高度 
	}
	scanf("%d",&height);			//输入身高 
	for(i = 0; i < 10; i++)
	{
		if(height + chair >= a[i])
		count++;					//如果身高加板凳的高度 >= 苹果的高度，那么数量加 1 
	}
	printf("%d",count);
	return 0;
}
	
