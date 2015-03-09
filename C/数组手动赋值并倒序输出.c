#include<stdio.h>
int main(void)
{
 int a[10],i,n;
 printf("please input 10 numbers\n");
 for(i=0;i<=9;i++)
  scanf("%d",&a[i]);
  for(i=9;i>=0;i--)
  printf("%d ",a[i]);
  printf("\n");

 return(0);
}