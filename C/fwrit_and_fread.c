#include <stdio.h>
#include <stdlib.h>
#define N 2

struct s
{
	char name[10];
	int chinese;
	int math;
	int english;
}score[100];//����ȫ�ֱ��� 

int save(char name[])
{
	FILE *fp;
	int i;
	fp = fopen(name,"wb");//�����ļ� 
	if(fp == NULL)
	{
		printf("can not create %s",name);
		exit(0);
	}
	printf("created file seccessful\n");
	for(i = 0; i < N; i++)
	{
		fwrite(&score[i],sizeof(struct s),1,fp);//�������е�����д�뵽�ļ� 
	}
	fclose(fp);
}

int show(char name[])
{
	int i;
	FILE *fp;
	fp = fopen(name,"rb");
	if(fp == NULL)
	{
		exit(0);
	}
	for(i = 0; i < N; i++)
	{
		fread(&score[i],sizeof(struct s),1,fp);//��ȡ�ļ��е����ݵ����� 
		printf("%s\t%d\t%d\t%d\n",score[i].name,score[i].chinese,score[i].math,score[i].english);//������� 
	}
	fclose(fp);
}

int main()
{
	char name[10];
	int i;
	printf("�������ļ����洢�ɼ���");
	scanf("%s",name);
	getchar();
	printf("���������������ģ���ѧ��Ӣ��\n");
	for(i = 0; i < N; i++)
	{
		scanf("%s %d %d %d",score[i].name, &score[i].chinese, &score[i].math, &score[i].english);//�����ݴ������� 
	}
	save(name);//�洢���ݵ��ļ� 
	show(name);//��ȡ�ļ� 
	return 0;
}
