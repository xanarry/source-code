#include <stdio.h>
#include <string.h>
int main()
{
	char a[20];
	int b[20];
	int i,j,k,t;
	gets(a);								//��ȡ�ַ��� 
	for(i = 0, j = 0; i < strlen(a); i++)
	{
		if(a[i] >= 48 && a[i] <= 57)
		{
			b[j] = a[i]-48;					//��ȡ�ַ����е����֣��洢���µ����� 
			j++;
		}
	}
	for(k = 0; k < j-1; k++)
	{
		for(i = 0; i < j-1-k; i++)
		{
			if(b[i] > b[i+1])
			{
				t = b[i];
				b[i] = b[i+1];
				b[i+1] = t;
			}
		}
	}										//���������� 
	for(i = 0; i < j; i++)
	{
		printf("%d ",b[i]);
	}										//������� 
	return 0;
}
