#include<stdio.h>
int main()
{
	void sort(int array[], int n);
	int a[10],i;
	printf("input ten nums\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);	
	}
	printf("------------------------\n");
	printf("have sorted\n");
	sort(a,10);
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);	
	}
	return 0;
}
void sort(int array[], int n)
{
	int i,t,j,k;
	for(i = 0; i < n-1; i++)
	{
		k = i;							//���ȵ�һ������������¼��������±� 
		for(j = i+1; j < n; j++)		//��������������Ƿ��б��������С���� 
		{
			if(array[j] < array[k])		//����� 
			k = j;						//��¼�µ��±� 
		}
     	if(k != i)						//����ҵ��˸�С������ 
    	{
			t = array[k];
			array[k] = array[i];
			array[i] = t;				//����λ�ã�������С�����ǵ�ǰ���� 
	    }
    }
}
	
