#include<stdio.h>

int main(void)
{
	int i,j,k;
	unsigned long long n,a=0;
	scanf("%llu",&n);
	printf("--------------------------------\n"); 
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n/5;j++)
		{
			for(k=0;k<=n/10;k++)
	      	{	
	        	if(i+j*5+k*10==n)
			 	{ 
	          		printf("1Ԫ%2d��   ��Ԫ%2d��   ʮԪ%2d��",i,j,k);
	          		a++;
	          		printf("\n");
	        	}
	      	}
		}	
	}
	printf("--------------------------------\n");    
	printf("һ����%llu��",a);
	return 0;
 }
