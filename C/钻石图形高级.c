#include<stdio.h>
int main(void)
{
	int n,j,i;
	scanf("%d",&n);
	for(i = 1; i <= n; i++)			//ÿ��ѭ�����й̶����� 
	{
		for(j = 1; j <= n-i; j++)
			printf(" ");			//����ÿ�еĿո� 
		for(j = 1; j <= 2*i-1; j++)
			printf("*");			//���"*" 
		printf("\n");				//������� 
	}
	//����������ͼ�ε��ϰ첿�֣��������°벿�֣��������������ѭ�� 
	for(i = n-1; i >= 1; i--)
	{
		for(j = 1; j <= n-i; j++)
			printf(" ");
		for(j = 1; j <= 2*i-1; j++)
			printf("*");
		printf("\n");			
	} 
	return 0; 
}
