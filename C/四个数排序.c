#include<stdio.h>
void main()
{
 float a,b,c,d,t;
 printf("please input a b c d\n");
 scanf("%f %f %f %f",&a,&b,&c,&d);
 if (a<b)
    {t=a;
     a=b;
     b=t;}
 if (a<c)
    {t=a;
     a=t;
     c=t;}
 if (a<d)
    {t=a;
     a=d;
     d=t;}
 if (b<c)
    {t=b;
     b=c;
     c=t;}
 if (b<d)
    {t=b;
     b=d;
     d=t;}
 if (c<d)
    {t=c;
     c=d;
     d=t;}
printf("%.2f %.2f %.2f %.2f\n",a,b,c,d);
}

