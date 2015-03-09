#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	int j;
	int t;
	printf("以下数能完全平方且含有两个数相同：\n");
	for(i = 100; i < 1000; i++)
	{
		j = i;
		t = sqrt(j);
		if((t*t == j) && two_same(j)) //t为整形变量，如果开方后为整数则不用取整，t平方能够还原 
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
		i++;//分离各位数 
	}
	if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2])//比较是否有相同 
	return 1;
	else 
	return 0;
} 
