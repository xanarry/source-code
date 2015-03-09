#include<stdio.h>
void ave(float *p,int n)
{
	float sum = 0;
	int i;
	for(i = 0; i < n; i++)
	{
		sum += *(p+i);
	}
	printf("\naverage score is:%.2f\n",sum/12);
}

void search(float (*p)[4], int n)
{
	int j;
	printf("student_%d: ",n);
	for(j = 0; j < 4; j++)
	{
		printf("%-3.0f ", *(*(p+n-1)+j));
	}
}

int main()
{
	float a[3][4] = {{65,67,70,60},{80,87,90,81},{90,99,100,98}};//设定默认的分数 
	int i,j,k;
	printf("following is the score:\n\n");
	for(i = 0; i < 3; i++)
	{
		printf("student_%d: ",i+1);
		for(j = 0; j < 4; j++)
		{
			printf("%-3.0f ",a[i][j]);//输出默认成绩 
		}
		printf("\n");
	}
	ave(*a,12);//调用函数处理 
	printf("input a std_num:\n");
	scanf("%d",&k);//接收输出数组的序号 
	search(a,k);//调用函数输出 
}
