/*�ж����������е�ÿ��Ԫ�صĴ�С��������ȽϽ��*/
#include<stdio.h>
int main()
{   
	int compare(int x,int y);
	int a[10],b[10];
	int i,j;
	int n = 0, m = 0, k = 0;

	printf("input array a\n");
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);				//��������a 
	}
	printf("array a is:\n");
	
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);				//�������a 
	}
	
	printf("\n-------------------------------\n");             
	printf("input array b\n");
	for(j = 0; j < 10; j++)
	{
		scanf("%d",&b[j]);				//��������b 
	}
	
	printf("array a is:\n");
	for(j = 0; j < 10; j++)
	{
		printf("%d ",b[j]);				//�������b 
	}
	printf("\n-------------------------------\n");
	for(i = 0; i < 10; i++)
	{ 
		if(compare(a[i],b[i])==1) 
			n++;						//���ú��������a[i]>b[i] n�Լ�1 
	  	else if(compare(a[i],b[i])==0) 
		    m++;						//���ú��������a[i]==b[i] m�Լ�1
	  	else  
		  	k++;						//���ú��������a[i]<b[i] k�Լ�1
	}
	printf("array a is  bigger than array b %d times\n",n);
	printf("array a is  equal   to  array b %d times\n",m);
	printf("array a is smaller than array b %d times\n",k);
	return 0;
}

int compare(int x,int y)
{       
	int flag;
	if(x > y) 
		flag = 1; 						//���a[i]>b[i] flag = 1
	else if(x<y) 
		flag = -1;						//���a[i]>b[i] flag = -1
	else 
		flag = 0;						//���a[i]>b[i] flag = 0
	return (flag);						//���رȽϽ�� 
}
		
	  
	  	

