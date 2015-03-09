#include<stdio.h>
int main()
{
	int a[100];
	int n,i;
	int max,min;
	printf("请输入有多少个数\n");
	scanf("%d",&n);
	printf("请输入%d个数：\n",n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
    max = min = a[0];		//默认最大最小值都是a[0] 
    for(i = 0; i < n; i++)
    {   
		if(a[i] > max)
           max = a[i];		//找最大数 
        if(a[i] < min)
           min = a[i];		//找最小数 
	}
    printf("%d %d",max,min);
    return 0;
}
