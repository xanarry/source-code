#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *p;
	char path[20];
	char str[20];
	printf("请输入文件路径:");
	scanf("%s",path);
	p = fopen(path,"rt+");
	if(p == NULL)
	{
		printf("ERROR");
		exit(0);
	}
	while( fgets(str,sizeof(str),p) )
	{
		printf("%s",str);
	}
	fclose(p);
	return 0;
}
