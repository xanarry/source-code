#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	void range(int array[], int n);
	srand(time(NULL));
	int a[10],i,j;
	int *p;
	for(i = 0; i < 10; i++)
	{
		a[i] = rand()%10 + 1;			//Ϊ������������ 
	}
	for(i = 0,p = a; i < 10; i++,p++)
	{
		printf("%d ",*p);				//���ԭ���� 
	}
	printf("\n================================\n");
	range(a,10);						//���ú���ʹ���鷴�� 
	for(i = 0, p = a; i < 10; i++)
	{
		printf("%d ",*p++);				//������������� 
	}
	return 0;
}

void range(int array[], int n)
{
    int l,r,t;
    for(l = 0;l < (n-1)/2; l++)			//l��ʾ��ָ�� 
	{
	    r = n-l-1;						//r��ʾ��ָ�룬rͨ��l������� 
	    
	    t = array[l];
	    array[l] = array[r];
	    array[r] = t;					//34,35,36���ڽ������� 
	}
}	
