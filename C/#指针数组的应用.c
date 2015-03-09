#include<stdio.h>
int main()
{
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int (*p)[4];
	int i,j;
	for(p = a; p < a+3; p++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%2d ",*(*p+j));
		}
		printf("\n");
	}
	printf("int put location\n");
	scanf("%d %d",&i,&j);
	p = a+i-1;
	printf("a[%d][%d]=%d",i,j,*(*p+j-1));
	return 0;
}
