#include<stdio.h>
void insert(int array[],int a, int num)
{
	int i,k = a;
	for(i = 0; i < a; i++)
	{
		if(num <= array[i])
		{
			k = i;
			break;			//查找位置 
		}
	}
	for(i = a-1; i >= k; i--)
	{
		array[i+1] = array[i];
	}
	array[k] = num;			//插入元素 
}
int main()
{
	int a[11] = {1,3,21,23,25,41,46,56,66,76};
	int i,n,j;
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\ninput a num:\n");
	scanf("%d",&n);
	
	insert(a,10,n);			//调用函数 
	
	for(i = 0; i < 11; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
} 
