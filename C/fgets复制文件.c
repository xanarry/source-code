#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *pin;
	FILE *pout;
	char pathin[20];
	char pathout[20];
	char str[20];
	printf("������ԭ�ļ�·��:");
	scanf("%s",pathin);
	pin = fopen(pathin,"rt+");
	printf("�����븴���ļ���·��������:");
	scanf("%s",pathout);
	pout = fopen(pathout,"wt+");
	if(pin == NULL)
	{
		printf("READ��ERROR");
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
	printf("\n\n�ļ����Ƴɹ�\n");
	fclose(pin);
	fclose(pout);
	return 0;
}
