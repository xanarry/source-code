#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char path[10];
	char ch;
	FILE *fp;
	printf("please input a file path:");
	scanf("%s",path);
	fp = fopen(path,"r");
	if(fp == NULL)
	{
		printf("can not open this file, please check");
		exit(0);
	}
	printf("\n------first time output file:\n");
	ch = fgetc(fp);
	while(ch != EOF)
	{
		printf("%c",ch);
		ch = fgetc(fp);
	}
	printf("\n------continue output file:\n");
	ch = fgetc(fp);
	while(ch != EOF)
	{
		printf("%c",ch);
		ch = fgetc(fp);
	}
	printf("-----after use rewind function:\n");
	rewind(fp);
	ch = fgetc(fp);
	while(ch != EOF)
	{
		printf("%c",ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	return 0;
}
