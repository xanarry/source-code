#include<stdio.h>
int main()
{
	int a[3][3],i,j,max;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}     
	max = a[0][0];					//Ĭ�������һ��Ԫ�ص�ֵ����� 
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j] > max)		//������ҵ�һ�������max������ֵ��max 
			max = a[i][j];
		}
      }
	printf("%d",max);
	return 0;		   
}
