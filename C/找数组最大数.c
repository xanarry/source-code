#include<stdio.h>
int main()
{
    int a[100];
	int i,k,max,t,n;
	scanf("%d",&n);
	for(i = 0;i < n; i++)
	{ 
		scanf("%d",&a[i]);		//接受n个数 
	} 
	max = a[0];					//默认a[0]是最大值 
	for(i = 0; i < n; i++)
    { 
		if(a[i] > max)
        {
			max = a[i];			//将大的数给max 
          	k=i;				//记录下标 
		}
    }
	printf("max=%d %d",max,k);	//输出结果 
    return 0;
}
