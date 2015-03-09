/*
	Name: 摞盘子 
	Copyright: 
	Author: xiongyang 
	Date: 13/12/13 17:18
	Description: push表示放一个盘子，push后面是一个空格，后面是一个数字
	表示盘子的编号，新放的盘子在之前的上面，pop表示从中取出一个盘子，并
	输出取出盘子的编号；
	例如：
	输入
		push  1   
		push  3
		pop
		push  2
		push  5
		pop
		pop
		exit 
	输出
		3
		5
		2 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[10];
	int b[300];
	int t = 0;
	int in;
	scanf("%s",a);
	while(strcmp(a,"exit") != 0)
	{
		if(strcmp(a,"push") == 0)
		{
			scanf("%d",&in);
			b[t] = in;
			t++;
		}
		if(strcmp(a,"pop") == 0)
		{
			if(t > 0)
			{
				printf("%d\n",b[t-1]);
				t--;
			}
			else printf("ERROR");
			exit(1);
			
		}
		scanf("%s",a);		
	}
	return 0;
}
