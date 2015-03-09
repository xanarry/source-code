#include<stdio.h>
int main()
{
	int n,i,a,max,min;
	printf("请输入有多少个数：");
	scanf("%d",&n);
	printf("请输入%d个数\n",n);
	scanf("%d",&a);
	max = min = a; 
	for(i = 0; i < n-1; i++)
	{
	 	scanf("%d",&a);      
	 	if(a > max) max = a;
	 	if(a < min) min = a;
    }
    printf("max=%d\nmin=%d",max,min);
    return 0;
}
	 
