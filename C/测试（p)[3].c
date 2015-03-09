#include<stdio.h>
int main()
{
	int a[4][3]={{3,5,2},{7,3,4},{1,9,5},{6,3,9}};
	int i,j,n;
	int (*p)[3];
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("ÇëÊäÈëĞĞÊı:\n##########\n");
	scanf("%d",&n);
	for(j = 0; j < 3; j++)
	{
		printf("%d ",*(*(a+n-1)+j));
	}
	return 0;
}
