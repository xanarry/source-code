#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 


#define CREATE_NUM_5 (rand()%(36-1))+1
#define CREATE_NUM_2 (rand()%(13-1))+1
#define condition (n1 < n2) && (n2 < n3) && (n3 < n4) && (n4 < n5) && (n1 + n2 < 30) && (n4 + n5 > 50) && (n6 < n7)
#define FORMAT "��%02dע����:\t%02d %02d %02d %02d %02d + %02d %02d\n\n"
#define DATA count+1,n1,n2,n3,n4,n5,n6,n7

int cmp(void const *x, void const *y)
{
	return ( *(int *)y - *(int *)x );
}

struct no
{
	int a1;
	int a2;
	int a3;
	int a4;
	int a5;
	int a6;
	int a7;
};

int b[8][100001] = {0};
struct no piao[100001];
FILE *fp;
int main(int argc, char *argv[])
{
	srand(time(NULL));
	int n1,n2,n3,n4,n5,n6,n7;
	int count = 0;
	int t = 0;
	int temp;
	int no[8];
	int index[8][36] = {0};
	int i,j,k,n;
	fp = fopen("��ƱƵ����������.txt","w+");
	printf("\t\t��ƱƵ������������ v1.0\n\n");
	printf("������Ӷ��ٸ������н��з���(max = 100000)��");
	scanf("%d",&n);
	if(fp == NULL)
	{
		printf("�ļ�����ʧ�ܣ�\n");
	}
	printf("\n�����������ʺ�");
	fprintf(fp,"\n�����������ʺ�");
	printf("\n------------------------------------------------------------------\n");
	fprintf(fp,"\n------------------------------------------------------------------\n");
	while(1)
	{
		if(count == n)
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
			piao[t].a1 = n1;
			piao[t].a2 = n2;
			piao[t].a3 = n3;
			piao[t].a4 = n4;
			piao[t].a5 = n5;
			piao[t].a6 = n6;
			piao[t].a7 = n7;
			t++;
			count++;
		}
	}
	printf("\n------------------------------------------------------------------\n");
	fprintf(fp,"\n------------------------------------------------------------------\n");
	
	printf("\n�����Ǳ������");
	fprintf(fp,"\n�����Ǳ������");
	printf("\n------------------------------------------------------------------\n");
	fprintf(fp,"\n------------------------------------------------------------------\n");
	printf("������һ�����룺");
	fprintf(fp,"������һ�����룺");
	for(i = 0; i < t; i++)
	{
		b[1][i] = piao[i].a1;
		printf("%02d ",piao[i].a1);
		fprintf(fp,"%02d ",piao[i].a1);
	}
	printf("\n\n�����ڶ������룺");
	fprintf(fp,"\n\n�����ڶ������룺");
	for(i = 0; i < t; i++)
	{
		b[2][i] = piao[i].a2;
		printf("%02d ",piao[i].a2);
		fprintf(fp,"%02d ",piao[i].a2);
	}
	printf("\n\n�������������룺");
	fprintf(fp,"\n\n�������������룺");
	for(i = 0; i < t; i++)
	{
		b[3][i] = piao[i].a3;
		printf("%02d ",piao[i].a3);
		fprintf(fp,"%02d ",piao[i].a3);
	}
	printf("\n\n�������ĸ����룺");
	fprintf(fp,"\n\n�������ĸ����룺");
	for(i = 0; i < t; i++)
	{
		b[4][i] = piao[i].a4;
		printf("%02d ",piao[i].a4);
		fprintf(fp,"%02d ",piao[i].a4);
	}
	printf("\n\n������������룺");
	fprintf(fp,"\n\n������������룺");
	for(i = 0; i < t; i++)
	{
		b[5][i] = piao[i].a5;
		printf("%02d ",piao[i].a5);
		fprintf(fp,"%02d ",piao[i].a5);
	}
	printf("\n\n�������������룺");
	fprintf(fp,"\n\n�������������룺");
	for(i = 0; i < t; i++)
	{
		b[6][i] = piao[i].a6;
		printf("%02d ",piao[i].a6);
		fprintf(fp,"%02d ",piao[i].a6);
	}
	printf("\n\n�������߸����룺");
	fprintf(fp,"\n\n�������߸����룺");
	for(i = 0; i < t; i++)
	{
		b[7][i] = piao[i].a7;
		printf("%02d ",piao[i].a7);
		fprintf(fp,"%02d ",piao[i].a7);
	}
	printf("\n");
	fprintf(fp,"\n");
	printf("\n------------------------------------------------------------------\n\n");
	fprintf(fp,"\n------------------------------------------------------------------\n\n");

	printf("������Ƶ�ʷ������");
	fprintf(fp,"������Ƶ�ʷ������");
	printf("\n------------------------------------------------------------------\n");
	fprintf(fp,"\n------------------------------------------------------------------\n");
	for(i = 1; i <= 7; i++)
	{
		for(j = 0; j < t; j++)
		{
			for(k = 1; k <= 35; k++)
			{
				if(k == b[i][j])
				{
					index[i][k]++;
				}
			}	
		}
	}
	
	for(i = 1; i <= 7 ; i++)
	{
		temp = 0;
		printf("\n��%d�������Ƶ��",i);
		fprintf(fp,"\n��%d�������Ƶ��",i);
		printf("\n--------------------\n");
		fprintf(fp,"\n--------------------\n");
		for(j = 1; j <= 35; j++)
		{
			if(index[i][j] != 0) 
			{
				b[i][temp] = index[i][j];
				printf("����%02d����%d��\n\n",j,b[i][temp]);
				fprintf(fp,"����%02d����%d��.\n",j,b[i][temp]);
				temp++;
			}
		}
		qsort(b[i],temp,sizeof(int),cmp);
		printf("\n\t���Ƶ�� = %d\n",no[i] = b[i][0]);
		fprintf(fp,"\n\t���Ƶ�� = %d\n",no[i] = b[i][0]);
		printf("--------------------\n");
		fprintf(fp,"--------------------\n");
	} 
	
	printf("\n------------------------------------------------------------------\n");
	printf("    �������Ƶ�ʵ�������ͬʱ���ڶ��������������������̫�࣬����\n���պ�����ʹ���˸��ݷ�������������ϣ�ллʹ��!\n\n"); 
	printf("Ϊ�˷���鿴����Ļ��ʾ��������Ϣ����д���ļ�����ƱƵ����������.txt��\n\n\n");
	fprintf(fp,"\n------------------------------------------------------------------\n");
	fprintf(fp,"    �������Ƶ�ʵ�������ͬʱ���ڶ��������������������̫�࣬����\n���պ�����ʹ���˸��ݷ�������������ϣ�ллʹ��!\n\n"); 
	
	system("pause");
	return 0;
}
