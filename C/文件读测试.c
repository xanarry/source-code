#include <stdio.h>

int main()
{
	char path[25];
	printf("请输入文件路径:");
	scanf("%s",path);
	FILE *fp;
	fp = fopen(path,"r");
	if(fp != NULL)
		printf("文件打开成功！");
	else 
		printf("文件打开失败");
	fclose(fp);
	return 0;
}
