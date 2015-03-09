#include<stdio.h>
#define N 6
int main()
{
	int a[N],i;
	int min_index = 0,max_index = 0;
	printf("input %d nums\n",N);
	for(i = 0; i < N; i++)
	scanf("%d",&a[i]);
	for(i = 0; i < N; i++)
	{
		if(a[i] > a[max_index]) max_index = i;	//记录最大值的下标 
		if(a[i] < a[min_index]) min_index = i;	//记录最小值的下标 
	}
	printf("max=%d locate in:%d\nmin=%d locate in:%d",a[max_index],max_index+1,a[min_index],min_index+1);
	return 0;
}
