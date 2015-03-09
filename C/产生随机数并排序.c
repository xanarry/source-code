#include <stdio.h> 
#include <time.h> 
#include <stdlib.h>

int main(void)
{
	int i,j;
	int t;
	int a[10000];
	int n;
	srand(time(NULL));
	printf("请输入随机数个数：");
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		a[i] = rand()%10;		//这里产生10以内的数。可改为100,150,1000等 
	}
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i -1; j++)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for(i = 0; i < n; i++)
    printf("%d ",a[i]);
}
