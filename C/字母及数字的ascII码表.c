#include <stdio.h>

int main()
{
	FILE *fp;
	char i; 
	fp = fopen("��ĸ������ascII���.txt","w");
	if(fp != NULL)
	fprintf(fp,"��ĸ������ascII���\n");
	
	printf("��д��ĸ��\n");
	fprintf(fp,"��д��ĸ��\n");
	for(i = 'A'; i <= 'Z'; i++)
	{
		printf("%c -> %d\n",i,i);
		fprintf(fp,"%c -> %d\n",i,i);
	}
	
	printf("Сд��ĸ��\n");
	fprintf(fp,"Сд��ĸ��\n");
	for(i = 'a'; i <= 'z'; i++)
	{
		printf("%c -> %d\n",i,i);
		fprintf(fp,"%c -> %d\n",i,i);
	}
	
	printf("���֣�\n");
	fprintf(fp,"���֣�\n");
	for(i = '0'; i <= '9'; i++)
	{
		printf("%c -> %d\n",i,i);
		fprintf(fp,"%c -> %d\n",i,i);
	}
	return 0;
}
