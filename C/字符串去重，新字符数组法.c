#include <stdio.h>
#include <string.h>

char * un_same(char a[]); 
int main()
{
	char _original[100];
	puts("������һ���ַ���: ");
	gets(_original);
	puts("����������ĵ��ַ���: ");
	puts(_original);
	puts("�����ַ�ȥ�غ��Ч��: ");
	puts(un_same(_original));
	return 0;
} 

char * un_same(char a[])
{
	int i;
	int j;
	int t = 1; 
	int flag = 0;  
	char _new[100]; 
	_new[0] = a[0];
	for(i = 1; i < strlen(a); i++)//�󲿷ֵ��ַ� 
	{
		for(j = 0; j < i; j++) //ǰ���ֵ��ַ�  
		{	
			flag = 0;
			if(a[i] == _new[j]) //������ֺ�������ǰ����ͬ���ַ� 
			{
				flag = 1; 
				break;
			}
		}
		if(flag == 0)
		{
			_new[t] = a[i];				
			t++;
		}
	}
	_new[t] = '\0';
	strcpy(a,_new);
	return a;
}
