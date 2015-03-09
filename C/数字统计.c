#include <stdio.h>

int main()
{
	int l,r;
	int sum = 0;
	int i;
	int k,y;
	scanf("%d%d",&l,&r);
	for(i = l; i <= r; i++)
	{
		k = i;
		while(k > 0)
		{
			y = k%10;
			if(y == 2) sum++;
			k = k/10;
		}
	}
	printf("%d",sum);
}
