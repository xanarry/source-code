#include <stdio.h>

int main()
{
	int n;
	int t;
	int a[1000];
	int i;
	int to;
	int flag;
	printf("������ԭʮ������:");
	scanf("%d",&n);
	flag = n;
	printf("�����뽫Ҫת���Ľ���:");
	scanf("%d",&to);
	i = 0;
	while(n != 0)
	{
		t = n%to;
		a[i++] = t;
		n = n/to;
	}
	printf("%d��%d�������ǣ�",flag,to);
	for(n = i - 1; n >= 0; n--)
	{
		printf("%d",a[n]);
	}	
	printf("\n");
	return 0;
}
