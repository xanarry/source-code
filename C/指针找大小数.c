#include<stdio.h>
void main()
{
 int a,b;
 int *p1,*p2,*p;
 scanf("%d %d",&a,&b);
 p1=&a;
 p2=&b;
 if(a<b)
  {p1=&b,p2=&a;}
 printf("a=%d b=%d\n\n",a,b);
 printf("max=%d min=%d\n",*p1,*p2);
}