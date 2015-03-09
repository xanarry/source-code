#include<stdio.h>
void main()
{
 int a,b,s,g;
 a=100;
 while(a<1000)
  {
   b=a/100;
   s=(a-b*100)/10;
   g=a-b*100-s*10;
   if(b*100+s*10+g==b*b*b+s*s*s+g*g*g)
   printf("shui xian hua num is: %d\n",a);
   a++;
  }
}