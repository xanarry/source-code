#include<stdio.h>
void main()
{
 long int a,i,n,s=0;
 printf("input n!:\nn=");
 scanf("%d",&a);
 i=1;
 n=1;
 while(n<=a)
  {
   i=i*n;
   n++;
   s=s+i;
  }
 printf("%ld!=%ld 1!+2!+3!+...=%ld\n",a,i,s);
}