#include<stdio.h>
int max(int a,int b);
int main()
{
	int a,b,m;
 	printf("input a and b\n");
 	scanf("%d%d",&a,&b);
 	m = max(a,b);
 	printf("max=%d\n",m);
}

int max(int x,int y)
{
	if(x > y)
  		return x;
 	else 
  		return y; //直接返回大的数 
}  
