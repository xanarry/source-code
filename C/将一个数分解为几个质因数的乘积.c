#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	printf("%d=",n);
	for(i = 2; i <= n; i++)				//��Ϊ������2��ʼ�����Դ�2����ǰ��n֮���������� 
	{
		while(n != i)					//��ǰ��n����i��ͬʱ 
		{
			if(n%i == 0)				//�ж�ʱ���ܱ�2��n֮���һ�������� 
			{ 
				printf("%d*",i);		//����11�о���� ��i* �� 
				n = n/i;				//Ȼ����i��nȡ�� 
			}
			else
				break;					//���޷��ҵ�ʱ����ֹѭ�� 
		}
	}
	printf("%d",n);						//������ʣ�µ�n 
	return 0; 
}
