#include<stdio.h>
#include<string.h>
int main()
{
   char a[1000000];
   gets(a);					//数字太无法有整形储存，用字符串接收		
   if((a[strlen(a) - 1] - 48)%2 == 0) printf("yes");
   else printf("no");		//将将最后一位分离出来判断是否为偶数 
   return 0;
}
