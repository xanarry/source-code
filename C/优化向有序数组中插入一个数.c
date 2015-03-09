#include <stdio.h>

int main(void)
{
    int a[11] = { 9, 12, 21, 23, 32, 24, 34, 45, 51, 77}; 
    int i,j,n;
    int flag = 10;			//默认插入数到尾部 
    for(i=0; i<10; i++)
    { 
		printf("%d ", a[i]);
	} 
    printf("\n------------------------------\n输入一个数:");
    scanf("%d", &n);
	for(i = 0; i < 10; i++)
	{
		if(n < a[i])
		{
			flag = i;
			break; 			//找到新数在有序数组中的位置 
		}
	}
	printf("%d",flag);
	for(i = 9; i >= flag; i--)
	{
		a[i+1] = a[i];		//将找到位置后面的数后移一位 
	}
	a[flag] = n;			//插入新的数 
    printf("已经插入元素\n", n);
    for(i = 0; i < 11; i++)
    {
    	printf("%d ",a[i]);	//输入插入成功的数组 
    }
	return 0;	
}

