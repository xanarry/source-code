#include "stdio.h"
void main()
{
   	int n,i;
   	scanf("%d",&n);
   	if(n < 2) printf("no"); //С��2������������ 
      
  	for(i = 2; i < n; i++)
   	{
		if(n%i == 0)
     	{
      		printf("no");	//����ܱ�����һ���������������� 
       		break;
     	}
   }
   if(i == n)
   printf("yes");			//���ÿ������û�ܹ���������ô������ 
   return 0; 
}

