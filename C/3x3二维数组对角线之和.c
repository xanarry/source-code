#include<stdio.h>
int main()
{
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int i,j,sum = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if( (i+j) % 2 == 0)			//����ɸѡ���Խ���Ԫ�� 
         	{
            	sum = sum + a[i][j];	//���		
         	}	
		} 
	}   
  	prinprintf("%d\n",sum);
  	return 0;
}
