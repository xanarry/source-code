#include<stdio.h>
void main()
{
 int g;
 printf("please input grade\n");
 scanf("%d",&g);
 if (g>=90)
 printf("A\n");
 else if (80<=g<=89)
      printf("B\n");
      else if(70<=g<=79)
	   printf("C\n");
	   else if(60<=g<=69)
		printf("D\n");
		else printf("E\n");
}
