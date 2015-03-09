#include<stdio.h>
void main()
{
 int a[20],i;
 for (i=0;i<=19;i++)
       a[i]=i;
 for (i=19;i>=0;i--)
      printf("%d ",a[i]);
 printf("                                   \n");
 for (i=0;i<=19;i++)
 printf("%d ",a[i]);
  printf("\n");
}
         
