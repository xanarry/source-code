/******************************* 
�������������и���Ԫ�ص�����ֵ
********************************/ 
#include <stdio.h>
#include <math.h>
void sort1(int array[], int x)
{
	int t,j,i;
	for(j = 0;j < x-1; j++)
	{
		for(i = 0; i < x-i-1; i++)
		{
			if(array[i] > array[i+1])
			{
				t = array[i];
				array[i] = array[i+1];
				array[i+1] = t;
		    }
		}
	}
}				//����a���� 
void sort2(int array[], int x)
{
	int t,j,i;
	for(j = 0;j < x-1; j++)
	{
		for(i = 0; i < x-i-1; i++)
		{
			if(array[i] < array[i+1])
			{
				t = array[i];
				array[i] = array[i+1];
				array[i+1] = t;
		    }
		}
	}
}				//����b���� 
int main()
{
	int a[10000],b[1000],n,i,j,t = 0;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d",&b[i]);
	}
	sort1(a,n);
	sort2(b,n);
	for(i = 0; i < n; i++)
	{
		t += (abs(a[i]-b[i]));		//���������� 
	}
	printf("%d",t);
	return 0; 
}
	
	
