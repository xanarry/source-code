#include<stdio.h>
int main()
{
	int a[3][4]={{3,1,4,5},{-3,43,72,23},{33,54,52,64}}; //�趨�����ֵ 
   	int i,j,m,n,max;
	max = a[0][0];						//Ĭ�����ֵ��a[0][0] 
	for(i = 0; i < 3; i++)
	{ 
    	for(j = 0; j < 4; j++)
        {   
        	if(a[i][j] > max)			 
            max = a[i][j];
            m = i;
            n = j;						//�������Ԫ�ش���max������ֵ��max���������������Ƚϣ�����m,n��¼��������±� 
        }
	} 
   printf("max=%d\n",max);
   printf("%d %d\n",m,n);
   return 0;
}
           
