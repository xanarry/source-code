#include<stdio.h>
int prime(int a)
{
    int i;
    if(a<2) return 0;
    else 
    {
        for(i = 2; i < a; i++)
        if(a%i == 0)
        {
            return 0;
            break ;
        }
        if(i == a) return 1;				//定义函数筛选素数 
    }
}
int main()
{
    int n,x;
	for(n = 4; n < 101; n += 2)				//哥德巴赫的数的范围是4-100的偶数 
	{
		for(x = 2; x < n; x++)				//要分离成两个素数，那么任何一个加数肯定小于n,如果不想有两个加数交换位置的情况者用n/2 
	  	{
	    	if((prime(x)) && prime(n-x))	//如果两个加数都还是素数，则满足情况，输出 
	     	{
		  		printf("%2d+%2d=%3d\n",x,n-x,n);
	     	}
	  	} 									//break; 加上break就只输出第一个等式 
    }
	return 0;	 
}
