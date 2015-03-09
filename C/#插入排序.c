#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main()
{
	srand(time(NULL));
	int a[N];
	int i;
	int k;
	int j;
	for(i = 0; i < N; i++)
	{
		a[i] = rand()%50 + 1;
	}

	for(i = 1; i < N; i++)
	{
		k = a[i];//提取已经排序好元素后面的第一个元素 
		j = i-1; //已经排序好的元素的最后一个元素的下标
		while(a[j] > k && j >= 0)
		{//如果新元素比排好序的最后一个数小，就后移元素，知道有序数字中的数不再满足小于他的要求
			a[j+1] = a[j];
			j--;//后移元素 
		}
		a[j+1] = k;//插入元素到上面通过循环找到的位置
	}
		
	for(i = 0; i < N; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
