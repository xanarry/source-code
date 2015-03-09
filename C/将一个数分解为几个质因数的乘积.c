#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	printf("%d=",n);
	for(i = 2; i <= n; i++)				//因为素数从2开始，所以从2到当前的n之间找质因数 
	{
		while(n != i)					//当前的n不与i相同时 
		{
			if(n%i == 0)				//判读时否能被2到n之间的一个数整除 
			{ 
				printf("%d*",i);		//满足11行就输出 “i* ” 
				n = n/i;				//然后用i对n取整 
			}
			else
				break;					//但无法找到时，终止循环 
		}
	}
	printf("%d",n);						//输出最后剩下的n 
	return 0; 
}
