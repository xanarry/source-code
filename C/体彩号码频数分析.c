#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 


#define CREATE_NUM_5 (rand()%(36-1))+1
#define CREATE_NUM_2 (rand()%(13-1))+1
#define condition (n1 < n2) && (n2 < n3) && (n3 < n4) && (n4 < n5) && (n1 + n2 < 30) && (n4 + n5 > 50) && (n6 < n7)
#define FORMAT "第%02d注号码:\t%02d %02d %02d %02d %02d + %02d %02d\n\n"
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
	fp = fopen("彩票频数分析数据.txt","w+");
	printf("\t\t彩票频数分析数据器 v1.0\n\n");
	printf("您打算从多少个号码中进行分析(max = 100000)：");
	scanf("%d",&n);
	if(fp == NULL)
	{
		printf("文件创建失败！\n");
	}
	printf("\n以下是随机体彩号");
	fprintf(fp,"\n以下是随机体彩号");
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
	
	printf("\n以下是遍历结果");
	fprintf(fp,"\n以下是遍历结果");
	printf("\n------------------------------------------------------------------\n");
	fprintf(fp,"\n------------------------------------------------------------------\n");
	printf("遍历第一个号码：");
	fprintf(fp,"遍历第一个号码：");
	for(i = 0; i < t; i++)
	{
		b[1][i] = piao[i].a1;
		printf("%02d ",piao[i].a1);
		fprintf(fp,"%02d ",piao[i].a1);
	}
	printf("\n\n遍历第二个号码：");
	fprintf(fp,"\n\n遍历第二个号码：");
	for(i = 0; i < t; i++)
	{
		b[2][i] = piao[i].a2;
		printf("%02d ",piao[i].a2);
		fprintf(fp,"%02d ",piao[i].a2);
	}
	printf("\n\n遍历第三个号码：");
	fprintf(fp,"\n\n遍历第三个号码：");
	for(i = 0; i < t; i++)
	{
		b[3][i] = piao[i].a3;
		printf("%02d ",piao[i].a3);
		fprintf(fp,"%02d ",piao[i].a3);
	}
	printf("\n\n遍历第四个号码：");
	fprintf(fp,"\n\n遍历第四个号码：");
	for(i = 0; i < t; i++)
	{
		b[4][i] = piao[i].a4;
		printf("%02d ",piao[i].a4);
		fprintf(fp,"%02d ",piao[i].a4);
	}
	printf("\n\n遍历第五个号码：");
	fprintf(fp,"\n\n遍历第五个号码：");
	for(i = 0; i < t; i++)
	{
		b[5][i] = piao[i].a5;
		printf("%02d ",piao[i].a5);
		fprintf(fp,"%02d ",piao[i].a5);
	}
	printf("\n\n遍历第六个号码：");
	fprintf(fp,"\n\n遍历第六个号码：");
	for(i = 0; i < t; i++)
	{
		b[6][i] = piao[i].a6;
		printf("%02d ",piao[i].a6);
		fprintf(fp,"%02d ",piao[i].a6);
	}
	printf("\n\n遍历第七个号码：");
	fprintf(fp,"\n\n遍历第七个号码：");
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

	printf("以下是频率分析结果");
	fprintf(fp,"以下是频率分析结果");
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
		printf("\n第%d个号码的频数",i);
		fprintf(fp,"\n第%d个号码的频数",i);
		printf("\n--------------------\n");
		fprintf(fp,"\n--------------------\n");
		for(j = 1; j <= 35; j++)
		{
			if(index[i][j] != 0) 
			{
				b[i][temp] = index[i][j];
				printf("数字%02d出现%d次\n\n",j,b[i][temp]);
				fprintf(fp,"数字%02d出现%d次.\n",j,b[i][temp]);
				temp++;
			}
		}
		qsort(b[i],temp,sizeof(int),cmp);
		printf("\n\t最高频数 = %d\n",no[i] = b[i][0]);
		fprintf(fp,"\n\t最高频数 = %d\n",no[i] = b[i][0]);
		printf("--------------------\n");
		fprintf(fp,"--------------------\n");
	} 
	
	printf("\n------------------------------------------------------------------\n");
	printf("    由于最高频率的数可能同时存在多个，其号码排序组合种类太多，所有\n最终号码有使用人根据分析数据自主组合！谢谢使用!\n\n"); 
	printf("为了方便查看，屏幕显示的所有信息均已写入文件“彩票频数分析数据.txt”\n\n\n");
	fprintf(fp,"\n------------------------------------------------------------------\n");
	fprintf(fp,"    由于最高频率的数可能同时存在多个，其号码排序组合种类太多，所有\n最终号码由使用人根据分析数据自主组合！谢谢使用!\n\n"); 
	
	system("pause");
	return 0;
}
