#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p
{
	char ID[10];
	char name[20];
	float price;
	int count;
}product;
int main()
{
	product record;
	FILE *fp;
	int n;
	int num;
	char path[20];
	int i;
	printf("input file path and name:");
	scanf("%s",path);
	printf("input the count of products:");
	scanf("%d",&n);
	fp = fopen(path,"wb+");
	if(fp == NULL)
	{
		printf("CANNOT CREAT FILE");
		exit(0);
	}
	printf("input product information:\n");
	printf("+-------------------------+\n");
	for(i = 0; i < n; i++)
	{
		printf("input ID:");
		scanf("%s",record.ID);
		printf("input NAME:");
		scanf("%s",record.name);
		printf("input PRICE:");
		scanf("%f",&record.price);
		printf("input COUNT:");
		scanf("%d",&record.count);
		fwrite(&record, sizeof(record), 1, fp);
	}
	fclose(fp);
	fp = fopen(path,"rb");
	if(fp == NULL)
	{
		exit(0);
	}
	printf("ÇëÊäÈëÉÌÆ·ID:");
	scanf("%d",&num);
	fseek(fp, (num - 1) * sizeof(product), 0);
	printf("the product information you've input is:\n");
	printf("ID\tNAME\tPRICE\tCOUNT\n");
	printf("+----------------------------+\n");
	fread(&record, sizeof(record), 1, fp);
	printf("%s\t%s\t%.2f\t%d\n",record.ID, record.name, record.price, record.count);
	printf("+----------------------------+\n");
	fclose(fp);
	return 0;
}
