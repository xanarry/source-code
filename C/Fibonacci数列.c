#include<stdio.h>
void main()
{
 long int f1,f2;
 int i;
 f1=1;f2=1;
 for (i=1;i<=23;i++)
  {
   printf("%-12ld\n",f1);
   printf("%-12ld\n",f2);
   f1=f1+f2;
   f2=f2+f1;

  }
}