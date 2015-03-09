#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fin;
	FILE *fout;
	if(argc != 3)
	{
		printf("COMMANDLINE ERROR");
		exit(0);
	}
	
	fin = fopen(argv[1], "r");
	if(fin == NULL)
	{
		printf("NO DATA INPUT!");
		exit(0);
	}
	
	fout = fopen(argv[2], "w");
	if(fout == NULL)
	{
		printf("CAN NOT CREATE FILE");
		exit(0);
	}
	
	while(!feof(fin))
	{
		fputc(fgetc(fin),fout);
	}
	printf("文件复制完成！");
	
	fclose(fin);
	fclose(fout);
	return 0;
}
