#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define CREATE_NUM_5 (rand()%(36-1))+1
#define CREATE_NUM_2 (rand()%(13-1))+1
#define condition (n1 < n2) && (n2 < n3) && (n3 < n4) && (n4 < n5) && (n1 + n2 < 30) && (n4 + n5 > 50) && (n6 < n7)
#define FORMAT "%02d %02d %02d %02d %02d + %02d %02d\n"
#define DATA n1,n2,n3,n4,n5,n6,n7

int main(int argc, char *argv[])
{
	int num;
	int n1,n2,n3,n4,n5,n6,n7; 
	int count = 1;
	FILE *fp;
	srand(time(NULL));
	printf("\t\t------体育彩票号码生成器 V1.0------\n");
	printf("请输入生成数量：");
	scanf("%d",&num);
	while(num > 100000)
	{
		printf("您无法筛选如此多的号码！请重新输入:");
		scanf("%d",&num);
	}
	printf("%d",num);
	fp = fopen("随机体彩号码.txt","w");
	if(fp == NULL)
	{
		printf("文件创建失败！");
		exit(0);
	}
	printf("以下是随机生成号码：\n");
	while(1)
	{
		if(count == num)
			break;
		n1 = CREATE_NUM_5; 
		n2 = CREATE_NUM_5;
		n3 = CREATE_NUM_5;
		n4 = CREATE_NUM_5;
		n5 = CREATE_NUM_5;
		n6 = CREATE_NUM_2;
		n7 = CREATE_NUM_2;
		if(condition)
		{
			
			printf(FORMAT,DATA);
			fprintf(fp,FORMAT,DATA);
			count++;
		}
	}
	fclose(fp);
	printf("\n以上号码已经写到文件中！\n");
	system("pause");
	return 0;
}
