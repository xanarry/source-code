#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	void range(int array[], int n);
	srand(time(NULL));
	int a[10],i,j;
	int *p1;
	for(i = 0; i < 10; i++)
	{
		a[i] = rand()%10 + 1;			//为数组产生随机数
	}
	for(i = 0, p1 = a; i < 10; i++,p1++)
	{
		printf("%d ",*p1);				//输出原数组 
	}
	printf("\n================================\n");
	range(a,10);						//调用函数使数组反序
	for(i = 0, p1 = a; i < 10; i++)
	{
		printf("%d ",*p1++);			//输出处理后的数组
	}
	return 0;
}
void range(int *x, int n)
{
	int *p,t,*i,*j;
	for(i = x, j = x+n-1, p = x+(n-1)/2; i <= p; i++,j--)	//i，j，表示左指针 
	{
		t = *i;
		*i = *j;
		*j = t;							//31-33用于交换数据 
	}
}	
