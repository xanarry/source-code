#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	int j;
	int t;
	printf("����������ȫƽ���Һ�����������ͬ��\n");
	for(i = 100; i < 1000; i++)
	{
		j = i;
		t = sqrt(j);
		if((t*t == j) && two_same(j)) //tΪ���α��������������Ϊ��������ȡ����tƽ���ܹ���ԭ 
		{
			printf("%d=%d*%d\n",j,t,t); 
		}
	}
	return 0;
}

int two_same( int n)
{
	int a[3];
	int i = 0;
	while(n > 0)
	{
		a[i] = n%10;
		n = n/10;
		i++;//�����λ�� 
	}
	if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2])//�Ƚ��Ƿ�����ͬ 
	return 1;
	else 
	return 0;
} 
