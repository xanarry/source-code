#include<stdio.h>
int main()
{
	int n,i,j,a[11]={0,2,4,6,8,10,12,14,16,18}; //定义一个默认的有序数组 
	int t = 10;									//定义t记录查找到的下标，默认为最后一个，因为循环不能记录最后一个 
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);						//输入数组提示用户 
	}
 	printf("\n请输入一个数\n");
 	scanf("%d",&n);
 	printf("您输入的是 %d\n",n);
 	for(i = 0; i < 10; i++)
 	{
 		if(n < a[i])
 		{
 			t = i;
			break;								//查找新元素应该所处的位置 
 		}
 	}
 	for(i = 10; i > t; i-- )
 	{
 		a[i] = a[i - 1];						//将插入位置后面的元素后移 
 	}
 	a[t] = n;									//在查找到位置插入新元素 
 	for(i = 0; i <= 10; i++)
 	{
 		printf("%d ",a[i]);						//输入新的数组 
 	}
    return 0;
}    
