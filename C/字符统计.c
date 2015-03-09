#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE *p;
	char path[50];
	char ch;
	int low = 0;
	int upp = 0;
	int dig = 0;
	int pct = 0; 
	printf("请输入路径及文件名:");
	scanf("%s",path);
	getchar();
	p = fopen(path,"rt");
	if(p == NULL)
	{
		printf("NO DATA");
		return;
	}
	ch = fgetc(p);
	rewind(p);
	while(ch != EOF)
	{
		if(islower(ch)) low++;
		if(isupper(ch)) upp++;
		if(isdigit(ch)) dig++;
		if(ispunct(ch)) pct++;
		putchar(ch);
		ch = fgetc(p);
	}
	fclose(p);
	printf("\n小写字母有%d个.\n",low);
	printf("大写字母有%d个.\n",upp);
	printf("数字有%d个.\n",dig);
	printf("字符有%d个.\n",pct);
	return 0;
}

