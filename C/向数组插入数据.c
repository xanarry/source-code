#include<stdio.h>
int main()
{
	int i,a[100],b[100],n,num,m;
	printf("input how many nums in array\n");
	scanf("%d",&m);
	printf("input %d nums\n",m);
	for(i = 0; i < m; i++)
	{
		scanf("%d",&a[i]);				//����ԭ���� 
	}
	printf("array you input is:\n");  
	for(i = 0; i < m; i++)
	{
		printf("%d ",a[i]);				//���ԭ���� 
	} 
	printf("\n-----------------------------------------\n");
	printf("����������λ�ú���\n");
	scanf("%d %d",&n,&num);				//���ղ����λ�ú��� 
	printf("you'll insert %d to %dth\n",num,n);
	for(i = 0;i < n-1; i++)
	{
		b[i] = a[i];					//������λ��ǰ��������丳���µ����� 
	} 
	b[n-1] = num;						//��ָ��λ�ò������� 
	for(i = n; i < m+1; i++)
	{ 
		b[i] = a[i-1];					//������λ�ú����������� ��ͬ�¸��µ����� 
	} 
	for(i = 0;i < m+1; i++)
	{
		printf("%d ",b[i]);				//�������Ԫ�ص����� 
	}
	return 0;
}	    
