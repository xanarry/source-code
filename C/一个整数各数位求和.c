#include<stdio.h>
#include<string.h>
int main()
{
   char a[1000000];
   int sum = 0,i;
   gets(a);
   for(i = 0; i < strlen(a); i++)
   {
     sum = sum + (a[i] - 48);		//“-48 ”将字符数字转换为实体数字 
   }
   printf("%d\n",sum);
   return 0;
}
   
   
