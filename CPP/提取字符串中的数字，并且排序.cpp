#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a>b;
}											//����sort�����ıȽϵ��ú��� 

int main()
{
	int a[250];
	char b[20];
	int i,j;
	gets(b);								//�����ַ��� 
	for(i = 0, j = 0; i < strlen(b); i++)
	{
		if(b[i]>='0' && b[i]<='9')
		{
			a[j++] = b[i]-'0';				//��ȡ���� 
		}
	}
	
	sort(a,a+j,cmp);						//���ú���sort���� 
	
	for(int i = 0; i < j; i++)
	{
		printf("%4d",a[i]);
	}										//������� 
	return 0; 
}
