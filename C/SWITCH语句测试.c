#include<stdio.h>
void main()
{
 char a;
 a=getchar();
 (a>='A'&&a<='D')? a:printf("input error,you can only input A-D\n");
 switch(a)
  {
   case'A':printf("85-100\n");break;
   case'B':printf("70-84\n");break;
   case'C':printf("60-69\n");break;
   case'D':printf("<60\n");break;
  }
}
