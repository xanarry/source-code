#include <stdio.h>
#include <stdlib.h>
#define N 2

struct s
{
	char name[10];
	int chinese;
	int math;
	int english;
}score[100];//定义全局变量 

int save(char name[])
{
	FILE *fp;
	int i;
	fp = fopen(name,"wb");//创建文件 
	if(fp == NULL)
	{
		printf("can not create %s",name);
		exit(0);
	}
	printf("created file seccessful\n");
	for(i = 0; i < N; i++)
	{
		fwrite(&score[i],sizeof(struct s),1,fp);//将数组中的数据写入到文件 
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
		fread(&score[i],sizeof(struct s),1,fp);//提取文件中的数据到数组 
		printf("%s\t%d\t%d\t%d\n",score[i].name,score[i].chinese,score[i].math,score[i].english);//输出数组 
	}
	fclose(fp);
}

int main()
{
	char name[10];
	int i;
	printf("请输入文件名存储成绩：");
	scanf("%s",name);
	getchar();
	printf("请输入姓名，语文，数学，英语\n");
	for(i = 0; i < N; i++)
	{
		scanf("%s %d %d %d",score[i].name, &score[i].chinese, &score[i].math, &score[i].english);//将数据存入数组 
	}
	save(name);//存储数据到文件 
	show(name);//读取文件 
	return 0;
}
