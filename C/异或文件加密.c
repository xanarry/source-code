#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#define CODE 0x3abcd//��16���Ƶ�������������� 

void encrypt()
{
	FILE *fp1;
	FILE *fp2;
	char ch;
	char name[20];
	printf("����������ܵ��ļ�:");
	scanf("%s",name);
	fp1 = fopen(name,"r");
	if(fp1 == NULL)
	{
		printf("�޷����ļ�����");
		exit(0);
	}
	fp2 = fopen("jianmi.txt","w");
	if(fp2 == NULL)
	{
		printf("�޷������ļ�");
		exit(0);
	} 
	ch = fgetc(fp1);
	while(ch != EOF)
	{
		fputc(ch ^ CODE, fp2);
		ch = fgetc(fp1);
	}
	
	fclose(fp1);
	fclose(fp2);
	
//	remove(name);
//	rename("encrypt.txt",name); ����Ҫ�ü��ܺ���ļ��滻ԭ�ļ���ȥ��������ע�� 
}

int main()
{
	encrypt();
	printf("���ܳɹ�"); 
	return 0;
}

