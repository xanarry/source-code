#include<stdio.h>
#include<math.h>
void main()
{
 float a,b,c,disc,x1,x2,realpart,imagpart;
 scanf("%f %f %f",&a,&b,&c);
 printf("the equation");
 if(fabs(a)<=1e-6)
   printf("is not a quadratic\n");
 else
  {
    disc=b*b-4*a*c;
    if(fabs(disc)<=1e-6)
      x1=-b/(a*2);
      printf("x1=x2=%f.2\n",x1);
    else
       if(disc>1e-6)
      {
	x1=(-b-sqrt(disc))/(2*a);
	x2=(-b+sqrt(disc))/(2*a);
	printf("x1=%.2f x2=%.2f\n",x1,x2);
       }
	else
	{
	realpart=-b/(2*a);
	imagpart=sqrt(-disc)/(2*a);
	printf("has complex roots: \n");
	printf("%f+%f\n",realpart,imagpart);
	printf("%f-%f\n",realpart,imagpart);
	}

  }
}