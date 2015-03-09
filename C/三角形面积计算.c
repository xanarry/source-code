#include<stdio.h>
#include<math.h>
void main()
{
 float a,b,c,tem,s;
 scanf("%f%f%f\n",&a,&b,&c);
 tem=1.0/2*(a+b+c);
 s=sqrt(tem*(tem-a)*(tem-b)*(tem-c));
 printf("area=%-7.2f\n",s);
 }
