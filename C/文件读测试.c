#include <stdio.h>

int main()
{
	char path[25];
	printf("�������ļ�·��:");
	scanf("%s",path);
	FILE *fp;
	fp = fopen(path,"r");
	if(fp != NULL)
		printf("�ļ��򿪳ɹ���");
	else 
		printf("�ļ���ʧ��");
	fclose(fp);
	return 0;
}
