#include<stdio.h>
int main()
{
	int a[100];
	int n,i;
	int max,min;
	printf("�������ж��ٸ���\n");
	scanf("%d",&n);
	printf("������%d������\n",n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
    max = min = a[0];		//Ĭ�������Сֵ����a[0] 
    for(i = 0; i < n; i++)
    {   
		if(a[i] > max)
           max = a[i];		//������� 
        if(a[i] < min)
           min = a[i];		//����С�� 
	}
    printf("%d %d",max,min);
    return 0;
}
