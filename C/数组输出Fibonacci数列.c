#include<stdio.h>
void main()
{
 long int a[23],i;
 a[0]=1;
 a[1]=1;
 for(i=2;i<23;i++)
 a[i]=a[i-2]+a[i-1];
 for(i=0;i<23;i++)
 {
  if(i%4==0)
  printf("\n");
  printf("%5.d\n",a[i]);
 }
}