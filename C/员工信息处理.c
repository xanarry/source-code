#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

struct worker
{
	int no;
	char name[20];
	int bumen;
	char sex;
	int salary;
};

int main()
{
	struct worker p[N];
	int i;
	int flag;
	char name[20];
	for(i=0; i<N; i++)
	{
		printf("�������%d��Ա����Ϣ,���� ���� ���� �Ա� ���ʣ�\n",i+1);
		scanf("%d %s %d %c %d",&p[i].no, p[i].name, &p[i].bumen, &p[i].sex, &p[i].salary);	
	}
		
	printf("�����������Ա����Ϣ:\n");
	printf("------------------------------------\n");
	printf("����\t����\t����\t�Ա�\t����\n");
	for(i=0; i<N; i++)
	{
		printf("%d\t%s\t%d\t%c\t%d\n",p[i].no, p[i].name, p[i].bumen, p[i].sex, p[i].salary);
	}
	printf("------------------------------------\n");
	
	for(i=0; i<N; i++)
	{
		if(p[i].bumen == 1) 
			p[i].salary += 100;
		else 
			p[i].salary += 200;
	}
	
	printf("\n�����Ǽ�н���Ա����Ϣ:\n");
	printf("------------------------------------\n");
	printf("����\t����\t����\t�Ա�\t����\n");
	for(i=0; i<N; i++)
	{
		printf("%d\t%s\t%d\t%c\t%d\n",p[i].no, p[i].name, p[i].bumen, p[i].sex, p[i].salary);
	}
	printf("------------------------------------\n");
	
	printf("\n������Ҫ���ҵ�����:");
	scanf("%s",name);
	
	printf("\n��������Ҫ���ҵ�Ա����Ϣ:\n");
	printf("------------------------------------\n");
	printf("����\t����\t����\t�Ա�\t����\n");
	for(i = 0; i < N; i++)
	{
		if(strcmp(p[i].name,name) == 0)
		printf("%d\t%s\t%d\t%c\t%d\n",p[i].no, p[i].name, p[i].bumen, p[i].sex, p[i].salary);
	}
	printf("------------------------------------\n");
	return 0;
}
