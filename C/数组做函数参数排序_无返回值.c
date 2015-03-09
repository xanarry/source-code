#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int sort(int array[], int n)
{
	int i,j,t;
	for(j = 0; j < n-1; j++)
	{ 
		for(i = 0;i < n-j-1; i++)
	  	{
	  		if(array[i+1] < array[i])
	  	  	{
	  	  		t = array[i+1];
	  	  		array[i+1] = array[i];
	  	  		array[i] = t;
	  	  	}
	  	}
	} 								//冒泡排序 
	for(i = 0;i < n; i++)
	{ 
		printf("%d ",array[i]);		//输出排序后的数组 
	} 
}
	  	  	
int main()
{
	srand(time(NULL));
	int a[10000],n,i,j;
	printf("how many nums you wanna sort\n");  
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{ 
		a[i] = rand()%100+1;		//给数组赋随机数 
	} 
	for(i = 0; i < n; i++)
	{ 
		printf("%d ",a[i]);			//输入原数组 
	}
	printf("\n");
	sort(a,n);						//调用函数排序（包含输出） 
	return 0;
}

