#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#define CODE 0x3abcd//用16进制的数进行异或运算 

void encrypt()
{
	FILE *fp1;
	FILE *fp2;
	char ch;
	char name[20];
	printf("请输入待加密的文件:");
	scanf("%s",name);
	fp1 = fopen(name,"r");
	if(fp1 == NULL)
	{
		printf("无法打开文件！！");
		exit(0);
	}
	fp2 = fopen("jianmi.txt","w");
	if(fp2 == NULL)
	{
		printf("无法创建文件");
		exit(0);
	} 
	ch = fgetc(fp1);
	while(ch != EOF)
	{
		fputc(ch ^ CODE, fp2);
		ch = fgetc(fp1);
	}
	
	fclose(fp1);
	fclose(fp2);
	
//	remove(name);
//	rename("encrypt.txt",name); 若果要用加密后的文件替换原文件则去掉这两行注释 
}

int main()
{
	encrypt();
	printf("加密成功"); 
	return 0;
}

