#include<stdio.h>
int main()
{
   int a,b,s,g;
   for(a = 100; a<1000; a++)
   {
   		b = a/100;		//�����λ 
   	  	s = a/10%10;		//����ʮλ 
   	  	g = a%10;			//�����λ 
   	 	if(b*100+s*10+g==(b*b*b+s*s*s+g*g*g))		//������������Ľ�� 
	 	printf("%d\n",a);
   }
   return 0;
} 
