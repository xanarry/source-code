#include<stdio.h>
void main()
{
 int n,leap;
 printf("please input the year\n");
 scanf("%d",&n);
 if (n%4==0)
    if (n%100==0)
       if (n%400==0)
       leap=1;
       else
       leap=0;
    else
    leap=1;
 else
 leap=0;
    if (leap)
     printf("yes %d is a leap year\n",n);
    else
     printf("no %d is not a leap year\n",n);
 }