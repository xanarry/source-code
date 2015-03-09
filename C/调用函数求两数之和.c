#include<stdio.h>
void main()
{
 float plus(float,float);
 float a,b,c;
 scanf("%f %f",&a,&b);
 c=plus(a,b);
 printf("a+b=%.2f\n",c);
}
 float plus(float x,float y)
 { float z;
   z=x+y;
   return(z);
 }
