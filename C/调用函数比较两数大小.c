#include<stdio.h>
void main()
{
 int max(int x,int y);
 int a,b,c;
 printf("input two numbers\n");
 scanf("%d %d",&a,&b);
 c=max(a,b);
 printf("max=%d\n",c);
}
 int max(int x,int y)
 {
   int z;
   z=x>y? x:y;
   return(z);
 }

