#include<stdio.h>
int main()
{
	int l,r,i,n=0,b,k;
	int a[100000];
	scanf("%d %d",&l,&r);
	for(i = 0, k =l; i <= r-l; i++,k++)
	{ 
		a[i] = k;
	} 
	for(i = 0;i <= r-l; i++)
	{
		while(a[i] > 0)
	 	{   
	    	b = a[i]%10;		//不断分离每一位数 
	 		if(b == 2) n++;		//将分离的数与2做比较	
	    	a[i] /= 10;			//取整辅助分离 
	 	}
	}
    printf("%d",n);
    return 0;
}

