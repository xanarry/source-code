#include<stdio.h>
void main()
{
char i,j,k;      /*i��a�Ƕ���;j��b�Ƕ���;k��c�Ķ���*/
for(i='x';i<='z';i++)
 for(j='x';j<='z';j++)
   {
     if(i!=j)
     for(k='x';k<='z';k++)
       {
         if(i!=k&&j!=k)
           { 
	     if(i!='x'&&k!='x'&&k!='z')
	     printf(":\na-%c\tb--%c\tc--%c\n",i,j,k);
           }
       }
   }
}