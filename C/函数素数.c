#include<stdio.h>
#include<math.h>
int isprime(int m)
{
	int i; 
	if(m < 2) return 0;				//如果传入的参数小于2，返回0 
	for(i = 2; i <= sqrt(m); i++)
	{ 
		if(m%i == 0) return 0;		//如果能够被其中的一个数整除，则不是素数 
    } 
    return 1 ;						//默认返回素数 
}
int main()
{
    int n,c=0;
	for(n = 2;n < 101; n++)			//输出1-100的素数 
	{
		if(isprime(n) == 1) 
	 	{
	 		printf("%d ",n);		//如果是素数则输出这个数 
	 		c++;
	 		if(%5==0) 		
			printf("\n");			//5个数一换行 
     	}
	}
	return 0;
}
