#include <stdio.h>
#include <string.h>

int main()
{
	char a[100];
	int pos;
	int len;
	int l;
	int i;
	printf("������ԭ�ַ���:\n");
	gets(a);
	puts("����������ĵ�ԭ�ַ�����");
	puts(a);
	l = strlen(a);
	printf("������ɾ����λ�ü�����:");
	scanf("%d %d",&pos,&len);
	for(i = pos-1; i < l; i++)
	{
		a[i] = a[i + len];//����ʼλ��֮���ÿ���ַ���ǰ�ƶ�len��λ�� 
	}
	a[l - len] = '\0';//�����ַ���len���� 
	puts(a); 
	return 0;
}
