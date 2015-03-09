#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	void range(int array[], int n);
	srand(time(NULL));
	int a[10],i,j;
	int *p;
	for(i = 0; i < 10; i++)
	{
		a[i] = rand()%10 + 1;			//为数组产生随机数 
	}
	for(i = 0,p = a; i < 10; i++,p++)
	{
		printf("%d ",*p);				//输出原数组 
	}
	printf("\n================================\n");
	range(a,10);						//调用函数使数组反序 
	for(i = 0, p = a; i < 10; i++)
	{
		printf("%d ",*p++);				//输出处理后的数组 
	}
	return 0;
}

void range(int array[], int n)
{
    int l,r,t;
    for(l = 0;l < (n-1)/2; l++)			//l表示左指针 
	{
	    r = n-l-1;						//r表示右指针，r通过l计算出来 
	    
	    t = array[l];
	    array[l] = array[r];
	    array[r] = t;					//34,35,36用于交换数据 
	}
}	
