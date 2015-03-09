#include<stdio.h>
int main()
{
	int a[3][3];						//定义数组大小 
	int i,j;
	int *p = a;							//定义整形指针指向数组a 
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j ++)
		{
			scanf("%d",(*(a+i) + j));	//*(a+i)等同于a[i],表示行，j表示列 
		}
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3;)
		{
			printf("%d ", *( *(a+i) + (j++)));
		}								//同11行注释 
		printf("\n");
	}
	return 0;
}
