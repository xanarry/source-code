#include<stdio.h>
int main()
{
	int temp[10];
	int a[1000];
	int i,j,d=0;
	int n;
	printf("请输入有多少个元素:");
	scanf("%d",&n);
	printf("请输入有%d个元素:\n",n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(i = 0; i < n; i++)
	{
		temp[i] = a[i];
	  	for(j = 0; j < i; j++)
	    {
	    	if(a[i] == temp[j]) //将收到的数与前面的已接受的数比较 
			{
			 	d++;		 //没发现一个重复的数，d++表示重复的次数 
			 	break;
			} 
	    } 
	}
	printf("%d",n - d);		//数的个数减去重复的个数，表示不同的个数 
}
	
