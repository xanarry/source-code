#include <stdio.h>

char path[10];
int w(FILE *fp)
{
	char ch;
	if(fp == NULL)
	{
		printf("NO DATA");
		return;
	}
	ch = getchar();
	while(ch != EOF)
	{
		fputc(ch,fp);
		ch = getchar();
	}
	rewind(fp);
}
int r(FILE *p)
{
	char ch;
	if(p == NULL)
	{
		printf("NO DATA");
		return;
	}
	ch = fgetc(p);
	while(ch != EOF)
	{
		putchar(ch);
		ch = fgetc(p);
	}
}
int main()
{
	FILE *p;
	char path[50];
	printf("请输入路径及文件名:");
	scanf("%s",path);
	getchar();
	p = fopen(path,"wt+");
	w(p);
	r(p);
	return 0;
}


