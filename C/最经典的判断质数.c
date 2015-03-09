#include<stdio.h>
int main(void)
{
   int n,i;
   scanf("%d",&n);
   i = 2;
   while(n%i != 0)
	   i++;
   if(i == n)
	   printf("YES \n");
   else 
	   printf("No \n");
}

