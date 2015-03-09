/*判断两个数组中的每个元素的大小，并输出比较结果*/
#include<stdio.h>
int main()
{   
	int compare(int x,int y);
	int a[10],b[10];
	int i,j;
	int n = 0, m = 0, k = 0;

	printf("input array a\n");
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);				//输入数组a 
	}
	printf("array a is:\n");
	
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);				//输出数组a 
	}
	
	printf("\n-------------------------------\n");             
	printf("input array b\n");
	for(j = 0; j < 10; j++)
	{
		scanf("%d",&b[j]);				//输入数组b 
	}
	
	printf("array a is:\n");
	for(j = 0; j < 10; j++)
	{
		printf("%d ",b[j]);				//输出数组b 
	}
	printf("\n-------------------------------\n");
	for(i = 0; i < 10; i++)
	{ 
		if(compare(a[i],b[i])==1) 
			n++;						//调用函数，如果a[i]>b[i] n自加1 
	  	else if(compare(a[i],b[i])==0) 
		    m++;						//调用函数，如果a[i]==b[i] m自加1
	  	else  
		  	k++;						//调用函数，如果a[i]<b[i] k自加1
	}
	printf("array a is  bigger than array b %d times\n",n);
	printf("array a is  equal   to  array b %d times\n",m);
	printf("array a is smaller than array b %d times\n",k);
	return 0;
}

int compare(int x,int y)
{       
	int flag;
	if(x > y) 
		flag = 1; 						//如果a[i]>b[i] flag = 1
	else if(x<y) 
		flag = -1;						//如果a[i]>b[i] flag = -1
	else 
		flag = 0;						//如果a[i]>b[i] flag = 0
	return (flag);						//返回比较结果 
}
		
	  
	  	

