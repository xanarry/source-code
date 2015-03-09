#include <stdio.h>
int main()
{
	int x,sum;
	scanf("%d",&x);
	sum = 0;
	do
	{
		sum += x%10;   	//求余相加 
		x /= 10; 		//不断取整 
	}while(x > 0);
	printf("%d",sum);
	return 0;
	
} 
