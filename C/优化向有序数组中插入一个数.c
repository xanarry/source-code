#include <stdio.h>

int main(void)
{
    int a[11] = { 9, 12, 21, 23, 32, 24, 34, 45, 51, 77}; 
    int i,j,n;
    int flag = 10;			//Ĭ�ϲ�������β�� 
    for(i=0; i<10; i++)
    { 
		printf("%d ", a[i]);
	} 
    printf("\n------------------------------\n����һ����:");
    scanf("%d", &n);
	for(i = 0; i < 10; i++)
	{
		if(n < a[i])
		{
			flag = i;
			break; 			//�ҵ����������������е�λ�� 
		}
	}
	printf("%d",flag);
	for(i = 9; i >= flag; i--)
	{
		a[i+1] = a[i];		//���ҵ�λ�ú����������һλ 
	}
	a[flag] = n;			//�����µ��� 
    printf("�Ѿ�����Ԫ��\n", n);
    for(i = 0; i < 11; i++)
    {
    	printf("%d ",a[i]);	//�������ɹ������� 
    }
	return 0;	
}

