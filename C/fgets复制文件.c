#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *pin;
	FILE *pout;
	char pathin[20];
	char pathout[20];
	char str[20];
	printf("请输入原文件路径:");
	scanf("%s",pathin);
	pin = fopen(pathin,"rt+");
	printf("请输入复制文件的路径及名字:");
	scanf("%s",pathout);
	pout = fopen(pathout,"wt+");
	if(pin == NULL)
	{
		printf("READ　ERROR");
		exit(0);
	}
	if(pout == NULL)
	{
		printf("WRITE ERROR");
		exit(0);
	} 
	while( fgets(str,sizeof(str),pin) )
	{
		printf("%s",str);
		fputs(str,pout);
	}
	printf("\n\n文件复制成功\n");
	fclose(pin);
	fclose(pout);
	return 0;
}
