#include <stdio.h>
int main()
{
	int a[1000],i,j,n,t;
 	printf("请输入您有多少个数要排序\n");
 	scanf("%d",&n);
 	printf("输入%d个数\n",n);
 	for(i = 0; i < n; i++)
 	{ 
 		scanf("%d",&a[i]);
 	} 
 	for(j = 0; j < n - 1; j++)				//一共需要n-1次 
 	{ 
   		for(i = 0; i < n-j-1; i++)			//内部只需要 n-j-1 次 
   		{ 
    		if(a[i] > a[i+1])
       		{
        		t = a[i];
        		a[i] = a[i+1];
        		a[i+1] = t;					//每次找到最大的数并排到最后去 
       		}
       	}
	} 
 	for(i = 0; i < n; i++)
 	{ 
 		printf("%d ",a[i]);					//输出已排序的数组 
 	} 
 	printf("\n");
 	return 0;
}
