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
	printf("������·�����ļ���:");
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
	printf("\nСд��ĸ��%d��.\n",low);
	printf("��д��ĸ��%d��.\n",upp);
	printf("������%d��.\n",dig);
	printf("�ַ���%d��.\n",pct);
	return 0;
}

