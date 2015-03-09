#include <stdio.h>
#include <stdlib.h>

typedef struct p
{
	char ID[10];
	char name[20];
	float price;
	int count;
}product;

void write(FILE *fp, int n);
void read(FILE *fp, int n);

int main()
{
	FILE *fp;
	int n;
	char path[20];
	printf("input file path and name:");
	scanf("%s",path);
	printf("input the count of products:");
	scanf("%d",&n);
	fp = fopen(path,"ab+");
	if(fp == NULL)
	{
		printf("CANNOT CREAT FILE");
		exit(0);
	}
	write(fp,n);
	read(fp,n);
	fclose(fp);
	return 0;
}

void write(FILE *fp, int n)
{
	product record;
	int i;
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
}

void read(FILE *fp, int n)
{
	product record;
	int i;
	float total = 0;
	rewind(fp);
	printf("the product information you've input is:\n");
	printf("ID\tNAME\tPRICE\tCOUNT\n");
	printf("+----------------------------+\n");
	while( fread(&record, sizeof(record), 1, fp) )
	{
		printf("%s\t%s\t%.2f\t%d\n",record.ID, record.name, record.price, record.count);
		total += record.count * record.price;
	}
	printf("+----------------------------+\n");
	printf("total price: %.2f",total);
}
