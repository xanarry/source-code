/************************
���ڲ�������һ����ȱʧ�ĵ���
����i love you
	i _ you
���룺love
************************/ 
#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	int i,j,l;
	int flag; 
	char str1[20];			
	char str2[20];							//���������ַ��� 
	scanf("%d",&n);
	getchar();								//�����������ֵĻس� 
	for(l = 0; l < n; l++)
	{
		gets(str1);
		gets(str2);
		for(j = 0; j < strlen(str2); j++)
		{
			if(str1[j] != str2[j])
			{
				flag = j;
				break;						//���������ַ����Ŀ�ʼ��ͬ���±� 
			}
		}
		for(i = j; i < strlen(str1); i++)
		{
			if(str1[i] == ' ' || str1[i] == '\0')	//��֮ǰ��¼�±괦������һ�����ʵĽ��� 
			{
				str1[i] = '\0';				//�ڽ�����λ�÷���'\0'��ֹ�ַ��� 
				break;						
			}
		}
		printf("%s",str1 + flag);			//���뵥�� 
	}
	return 0;
} 
