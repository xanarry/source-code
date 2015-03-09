#include<stdio.h>
void main()
{
 long int a,i,n;
 printf("input n!:\nn=");
 scanf("%d",&a);
 i=1;
 n=1;
 while(n<=a)
  {
   i=i*n;
   n++;
  }
 printf("%ld!=%ld\n",a,i);
}