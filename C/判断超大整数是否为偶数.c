#include<stdio.h>
#include<string.h>
int main()
{
   char a[1000000];
   gets(a);					//����̫�޷������δ��棬���ַ�������		
   if((a[strlen(a) - 1] - 48)%2 == 0) printf("yes");
   else printf("no");		//�������һλ��������ж��Ƿ�Ϊż�� 
   return 0;
}
