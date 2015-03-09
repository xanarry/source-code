#include<stdio.h>
int main()
{
	float score[5][4]={{67,87,66,89},{90,87,89,76},{97,78,96,76},{67,78,98,80},{89,98,79,80}};
	float *search(float (*pointer)[4],int n);//定义search函数是一个返回指针的函数，接收的两个形参分别为指向4个元素的指针和整形 
	int i,m;
	float *p;//定义一个指针变量接收search函数返回的行地址 
	printf("input student's no:");
	scanf("%d",&m);
	p = search(score,m);
	for(i=0;i<4;i++)
	{
		printf("%.2f ",*(p+i));//p是search函数返回的行地址，用循环输出这一行的值 
	}
	return 0;
}

float *search(float (*pointer)[4], int n)
{
	return *(pointer+n-1); //返回指针
}
