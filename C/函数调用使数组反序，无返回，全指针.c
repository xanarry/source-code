#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	void range(int array[], int n);
	srand(time(NULL));
	int a[10],i,j;
	int *p1;
	for(i = 0; i < 10; i++)
	{
		a[i] = rand()%10 + 1;			//Ϊ������������
	}
	for(i = 0, p1 = a; i < 10; i++,p1++)
	{
		printf("%d ",*p1);				//���ԭ���� 
	}
	printf("\n================================\n");
	range(a,10);						//���ú���ʹ���鷴��
	for(i = 0, p1 = a; i < 10; i++)
	{
		printf("%d ",*p1++);			//�������������
	}
	return 0;
}
void range(int *x, int n)
{
	int *p,t,*i,*j;
	for(i = x, j = x+n-1, p = x+(n-1)/2; i <= p; i++,j--)	//i��j����ʾ��ָ�� 
	{
		t = *i;
		*i = *j;
		*j = t;							//31-33���ڽ������� 
	}
}	
