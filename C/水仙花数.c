#include<stdio.h>
int main()
{
   int a,b,s,g;
   for(a = 100; a<1000; a++)
   {
   		b = a/100;		//分离百位 
   	  	s = a/10%10;		//分离十位 
   	  	g = a%10;			//分离个位 
   	 	if(b*100+s*10+g==(b*b*b+s*s*s+g*g*g))		//输入符合条件的结果 
	 	printf("%d\n",a);
   }
   return 0;
} 
