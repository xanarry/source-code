#include <stdio.h>

int main()
{
	int n;
	int a[3];
	scanf("%d",&n);
	int t;
	int i = 0;
	while(n > 0)
	{
		a[i] = n%10;
		n = n/10;
		i++;//�����λ�� 
	}
	if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) //�Ƚ��Ƿ�����ͬ 
	printf("yes\n");
	else
	printf("no\n"); 
	return 0;
} 
