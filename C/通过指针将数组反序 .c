#include <stdio.h>

int main()
{
	int a[10];
	int i;
	int *pl;
	int *pr;
	int t;
	printf("������10������");
	for(i=0; i<10; i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("�����������10������");
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
	printf("ͨ��ָ���Ѿ�������ʵ�ַ���");
	 for(i=0; i<10; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
