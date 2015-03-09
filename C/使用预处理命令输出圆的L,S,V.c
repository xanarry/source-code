#include<stdio.h>
#define PI 3.1415926
#define CIRCLE(R,L,S,V) L=2*PI*R;S=PI*R*R;V=4/3*PI*R*R*R
void main()
{
 float r,l,s,v;
 printf("R=");
 scanf("%f",&r);
 CIRCLE(r,l,s,v);
 printf("r=%-6.2f\nl=%-6.2f\ns=%-6.2f\nv=%-6.2f\n",r,l,s,v);
}