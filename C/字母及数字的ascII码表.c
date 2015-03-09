#include <stdio.h>

int main()
{
	FILE *fp;
	char i; 
	fp = fopen("字母和数字ascII码表.txt","w");
	if(fp != NULL)
	fprintf(fp,"字母和数字ascII码表\n");
	
	printf("大写字母：\n");
	fprintf(fp,"大写字母：\n");
	for(i = 'A'; i <= 'Z'; i++)
	{
		printf("%c -> %d\n",i,i);
		fprintf(fp,"%c -> %d\n",i,i);
	}
	
	printf("小写字母：\n");
	fprintf(fp,"小写字母：\n");
	for(i = 'a'; i <= 'z'; i++)
	{
		printf("%c -> %d\n",i,i);
		fprintf(fp,"%c -> %d\n",i,i);
	}
	
	printf("数字：\n");
	fprintf(fp,"数字：\n");
	for(i = '0'; i <= '9'; i++)
	{
		printf("%c -> %d\n",i,i);
		fprintf(fp,"%c -> %d\n",i,i);
	}
	return 0;
}
