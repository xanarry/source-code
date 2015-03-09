#include <stdio.h>
int main()
{
	int l,r,sum=0;
	int i,b,k;
	scanf("%d %d",&l,&r);
	for(i = l; i <= r;i++)
	{
		k = i;
		while(k > 0)
		{
			b = k%10;
			if(b == 3) 
				sum++;
			k = k/10;
		}	
	} 
	printf("%d",sum);
}
