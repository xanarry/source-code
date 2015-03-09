#include<stdio.h>
int main()
{   
    int i,k,temp;
	int a[10];
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}  							//输入10个数 
	for(i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);	
	}   						//输出输入10的数 
	printf("\n");   			//输出换行 
    for(i = 0; i < 10; i++)
	{
		if(a[i] > a[i+1])		//依次将前后两个数作比较 
	   	{
	   		temp = a[i];
	   	  	a[i] = a[i+1];
	   	  	a[i+1] = temp;		//如果前一个大于后一个做交换，最后最大的数将会到数组尾部 
	   	}
	}
	for(i = 0; i < 10; i++)
	{ 
		printf("%d ", a[i]);	
	}    
	return 0;    
}
