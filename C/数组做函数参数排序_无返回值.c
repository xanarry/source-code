#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int sort(int array[], int n)
{
	int i,j,t;
	for(j = 0; j < n-1; j++)
	{ 
		for(i = 0;i < n-j-1; i++)
	  	{
	  		if(array[i+1] < array[i])
	  	  	{
	  	  		t = array[i+1];
	  	  		array[i+1] = array[i];
	  	  		array[i] = t;
	  	  	}
	  	}
	} 								//ð������ 
	for(i = 0;i < n; i++)
	{ 
		printf("%d ",array[i]);		//������������� 
	} 
}
	  	  	
int main()
{
	srand(time(NULL));
	int a[10000],n,i,j;
	printf("how many nums you wanna sort\n");  
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{ 
		a[i] = rand()%100+1;		//�����鸳����� 
	} 
	for(i = 0; i < n; i++)
	{ 
		printf("%d ",a[i]);			//����ԭ���� 
	}
	printf("\n");
	sort(a,n);						//���ú������򣨰�������� 
	return 0;
}

