#include<stdio.h>
int main()
{
	int i,t = 1;
	unsigned long long a,b;
	scanf("%llu%llu",&a,&b);				//输入两个数 
    for(i = 1; i < 100; i++)				//i相当于10的次方数 
	{
    	if( (1 <= ( (a*b) / t)) && ( ((a*b) / t) <= 9) ) //如果两个数的乘积除以t后>1并且<9,
    	{ 
			break;
		} 
     	t *= 10;							//如果不满足，则是t的值扩大10倍 
    }
    printf("%d",i);							//输出次方数，即乘积是多少位 
    return 0;
 }
