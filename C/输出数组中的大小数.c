#include<stdio.h>
void main()
{
 int a[10],max,min,i,j,k;
 for(i=0;i<10;i++)
  {
   scanf("%d",&a[i]);
  }
   printf("10 numbers you input is:\n");
   for(i=0;i<10;i++)
   printf("%d ",a[i]);
   printf("\n");
 max=a[0];
 for(j=0;j<10;j++)
  {
   if(max<a[j])
      max=a[j];
  }
 for(k=0;k<10;k++)
  {
   if(min>a[k])
      min=a[k];
  }
 printf("max=%d\nmin=%d\n",max,min);
}