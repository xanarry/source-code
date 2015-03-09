#include<stdio.h>
void main()
{
 int a,i;
 unsigned long b,n;
 float c,m;
 a=0;i=1;
 while(i<=100)
  {
   a=a+i;
   i++;
  }
 printf("a=%d\n",a);
 b=0;n=1;
 while(n<=50)
  {
   b=b+n*n;
   n++;
  }
 printf("b=%ld\n",b);
 c=0;m=1;
 while(m<=10)
  {
   c=c+1/m;
   m++;
  }
 printf("c=%.4f\n",c);
printf("a+b+c=%.4f\n",a+b+c);
}