#include<stdio.h>
#include<math.h>
int isprime(int m)
{
	int i; 
	if(m < 2) return 0;				//�������Ĳ���С��2������0 
	for(i = 2; i <= sqrt(m); i++)
	{ 
		if(m%i == 0) return 0;		//����ܹ������е�һ������������������ 
    } 
    return 1 ;						//Ĭ�Ϸ������� 
}
int main()
{
    int n,c=0;
	for(n = 2;n < 101; n++)			//���1-100������ 
	{
		if(isprime(n) == 1) 
	 	{
	 		printf("%d ",n);		//������������������� 
	 		c++;
	 		if(%5==0) 		
			printf("\n");			//5����һ���� 
     	}
	}
	return 0;
}
