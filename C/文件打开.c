#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch;
	char path[25];
	FILE *fp;
	printf("请输入文件路径：");
	scanf("%s",path);
	fp = fopen(path,"r");
	if(fp == NULL)
	{
		printf("文件打开失败");
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
