#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch;
	char path[25];
	FILE *fp;
	printf("�������ļ�·����");
	scanf("%s",path);
	fp = fopen(path,"r");
	if(fp == NULL)
	{
		printf("�ļ���ʧ��");
		exit(1);
	}
	ch = fgetc(fp);
	while(ch != EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	return 0;
}
