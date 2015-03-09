#include <stdio.h>
#include <stdlib.h>

int main ()
{
	FILE * fp;
	char c;
	char path[50];
	printf("请输入新建文件的路径和名字:"); 
	scanf("%s",path);
	getchar();
	printf("请在下面输入文件内容:\n");
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
