#include <stdio.h>
int main()
{
	int x,sum;
	scanf("%d",&x);
	sum = 0;
	do
	{
		sum += x%10;   	//������� 
		x /= 10; 		//����ȡ�� 
	}while(x > 0);
	printf("%d",sum);
	return 0;
	
} 
