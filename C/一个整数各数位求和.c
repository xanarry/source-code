#include<stdio.h>
#include<string.h>
int main()
{
   char a[1000000];
   int sum = 0,i;
   gets(a);
   for(i = 0; i < strlen(a); i++)
   {
     sum = sum + (a[i] - 48);		//��-48 �����ַ�����ת��Ϊʵ������ 
   }
   printf("%d\n",sum);
   return 0;
}
   
   
