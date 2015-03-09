#include<stdio.h>
int main()
{
	int a[3][3];
	int i,j;
	int *p;
	for(p = a[0]; p < a[0] + 9; p++)			//a[0],表示第一行的地址 
	{
		scanf("%d",p);
	}
	for(p = a[0]; p < *a+9; p++)
	{
		printf("value=%d addr=%d  ",*p,p); 
		printf("\n");
	}
	return 0;
}
