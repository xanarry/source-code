#include<stdio.h>
int main()
{   
    int i,k,temp;
	int a[10];
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}  							//����10���� 
	for(i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);	
	}   						//�������10���� 
	printf("\n");   			//������� 
    for(i = 0; i < 10; i++)
	{
		if(a[i] > a[i+1])		//���ν�ǰ�����������Ƚ� 
	   	{
	   		temp = a[i];
	   	  	a[i] = a[i+1];
	   	  	a[i+1] = temp;		//���ǰһ�����ں�һ����������������������ᵽ����β�� 
	   	}
	}
	for(i = 0; i < 10; i++)
	{ 
		printf("%d ", a[i]);	
	}    
	return 0;    
}
