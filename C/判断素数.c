#include "stdio.h"
void main()
{
   	int n,i;
   	scanf("%d",&n);
   	if(n < 2) printf("no"); //小于2的数不是素数 
      
  	for(i = 2; i < n; i++)
   	{
		if(n%i == 0)
     	{
      		printf("no");	//如果能被其中一个数整除不是素数 
       		break;
     	}
   }
   if(i == n)
   printf("yes");			//如果每个数都没能够整除，那么是素数 
   return 0; 
}

