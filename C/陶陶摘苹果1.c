#include<stdio.h>
int main()
{
	int a[10],height,i,count=0;
	const int chair=30;				//��ͬ��define 
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);			//����ÿ��ƻ���ĸ߶� 
	}
	scanf("%d",&height);			//������� 
	for(i = 0; i < 10; i++)
	{
		if(height + chair >= a[i])
		count++;					//�����߼Ӱ�ʵĸ߶� >= ƻ���ĸ߶ȣ���ô������ 1 
	}
	printf("%d",count);
	return 0;
}
	
