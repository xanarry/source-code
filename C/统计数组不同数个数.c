#include<stdio.h>
int main()
{
	int temp[10];
	int a[1000];
	int i,j,d=0;
	int n;
	printf("�������ж��ٸ�Ԫ��:");
	scanf("%d",&n);
	printf("��������%d��Ԫ��:\n",n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(i = 0; i < n; i++)
	{
		temp[i] = a[i];
	  	for(j = 0; j < i; j++)
	    {
	    	if(a[i] == temp[j]) //���յ�������ǰ����ѽ��ܵ����Ƚ� 
			{
			 	d++;		 //û����һ���ظ�������d++��ʾ�ظ��Ĵ��� 
			 	break;
			} 
	    } 
	}
	printf("%d",n - d);		//���ĸ�����ȥ�ظ��ĸ�������ʾ��ͬ�ĸ��� 
}
	
