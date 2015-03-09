#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char file1[10];
	char file2[10];
	char ch;
	FILE *fp1,*fp2;
	printf("please input file1:");
	scanf("%s",file1);
	fp1 = fopen(file1,"a+");
	if(fp1 == NULL)
	{
		printf("can not use this file");
		exit(0);
	}
	printf("open %s seccessful\n",file1);
	
	printf("please input file2:");
	scanf("%s",file2);
	fp2 = fopen(file2,"r");
	if(fp2 == NULL)
	{
		printf("can not use this file");
		exit(0);
	}
	printf("open %s seccessful\n",file2);
	
	printf("file1 is:\n");
	ch = fgetc(fp1);
	while(ch != EOF)
	{
		printf("%c",ch);
		ch = fgetc(fp1);
	}
	
	printf("\nfile2 is:\n");
	ch = fgetc(fp2);
	while(ch != EOF)
	{
		printf("%c",ch);
		ch = fgetc(fp2);
	}
	
	rewind(fp2);
	printf("\ntwo file have emerged in %s:\n",file1);
	ch = fgetc(fp2);
	while(!feof(fp2))
	{
		fputc(ch,fp1);
		ch = fgetc(fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
