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
	printf("\t\t------������Ʊ���������� V1.0------\n");
	printf("����������������");
	scanf("%d",&num);
	while(num > 100000)
	{
		printf("���޷�ɸѡ��˶�ĺ��룡����������:");
		scanf("%d",&num);
	}
	printf("%d",num);
	fp = fopen("�����ʺ���.txt","w");
	if(fp == NULL)
	{
		printf("�ļ�����ʧ�ܣ�");
		exit(0);
	}
	printf("������������ɺ��룺\n");
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
	printf("\n���Ϻ����Ѿ�д���ļ��У�\n");
	system("pause");
	return 0;
}
