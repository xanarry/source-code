#include<stdio.h> 
int main()
{
	int a[2][3]={{1,2,3}, {4,5,6}};   	//����һ��2x3�����鲢�Ҹ�ֵ 
	int b[3][2], i, j;					//����һ��3x2���������ת���������	
	printf("array a:\n");
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 3; j++)			
	   	{
	   		printf("%5d", a[i][j]);		
	    	b[j][i] = a[i][j];			//�����Ԫ�����ͬʱ��ת�����鲢�ҽ��丳���µ����飬�������±꽻���� 
	    }
	}
	printf("\n");

	printf("array b:\n");
    for(i = 0; i < 3; i++)
	{
	    for(j = 0; j < 2; j++)
	    {
	    	printf("%5d", b[i][j]);		//���ת�������� 
	    	printf("\n");
	    }
	}	
	return 0;	   
}
