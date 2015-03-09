#include<stdio.h>
void main()
{
 float sn=100.0,hn=sn/2;
 int n;
 for(n=2;n<=10;n++)
     {
       sn=sn+2*hn;
       hn=hn/2;
     }
 printf("total height is:%f\n",sn);
 printf("nth's height is:%f\n",hn);
}
         
