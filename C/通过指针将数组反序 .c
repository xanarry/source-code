#include <stdio.h>

int main()
{
	int a[10];
	int i;
	int *pl;
	int *pr;
	int t;
	printf("请输入10个数：");
	for(i=0; i<10; i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("这是您输入的10个数：");
	for(i=0; i<10; i++)
	{
		printf("%d ",a[i]);
	}
	
	pl = a;
	pr = a+9;
	while(pl < pr)
	{
		t = *pl;
		*pl = *pr;
		*pr = t;
		pl++;
		pr--;
	}
	
	printf("\n");
	printf("通过指针已经将数组实现反序：");
	 for(i=0; i<10; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
