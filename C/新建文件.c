#include <stdio.h>
#include <stdlib.h>

int main ()
{
	FILE * fp;
	char c;
	char path[50];
	printf("�������½��ļ���·��������:"); 
	scanf("%s",path);
	getchar();
	printf("�������������ļ�����:\n");
	fp = fopen (path,"w");
	if (fp == NULL) 
	{
		printf("ERROR");
		exit(0);
	}
	c = getchar();
	while(c != EOF)
	{
		fputc (c,fp);
  	 	c = getchar();
  	}
	fclose (fp);
  	return 0;
}
