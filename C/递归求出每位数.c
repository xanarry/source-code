#include<stdio.h>
int function(int n)
{
	if(n < 10) 					//��nΪһλ����ʱ��
	printf("%d",n);				//ֱ������� 
	else						//�������һλ�� 
	{
		function(n/10);			//����ȡ�� 
		if(n != 0) 
		printf(" %d", n%10);	//����ȡ���������ʵ�ַ���							 
	}
}								//8 10�н����ͷ������
int main()
{
	int x;
	scanf("%d", &x); 
	function(x);				//���ú��� 
	return 0;
}
