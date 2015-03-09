#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

	/*全局变量*/ 
int len;//用户设定密码长度 
int new_len;//更改字符集后的字符数组长度 
int times;//生成密码数量 
int i;//循环使用 
int n = 0;//计数器 
int flag = 0;//0表示使用默认字符集 
FILE *fp;//文件指针，写数据到文件 
char _new[100];//用户自定义字符集 
char original[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '=', '+'};//默认字符集 

int main()
{
	int choose; //第一次选择 
	int choose1;//第二次选择 
	int i;
	printf("--------------------\n");
	printf("1 只有数字\n");
	printf("2 只有字母\n");
	printf("3 只有符号\n");
	printf("4 数字+字母\n");
	printf("5 数字+符号\n");
	printf("6 字母+符号\n");
	printf("7 数字+字母+符号\n");
	printf("--------------------\n");//输出目录列表 
	
	printf("请选择：");
	scanf("%d",&choose);
	
	if(choose == 3 || choose == 5 || choose == 7 || choose == 6)//选择内容涉及字符则询问采用默认字符还是自定义 
	{
		system("cls");
		printf("----------------------\n"); 
		printf("使用系统默认符号请按 0\n");
		printf("自定义请按 1\n");
		printf("----------------------\n"); 
		printf("choose：");
		scanf("%d",&choose1);
		if(choose1 == 1)	
		{
			system("cls");
			printf("请输入您要包含的字符:\n");
			scanf("%s",_new);
			flag = 1;//记录是否采用自定义支付 
			new_len = strlen(_new);//记录字符个数 
		}
	}
	printf("请输入密码长度:");
	scanf("%d",&len); 
	printf("请输入生成密码数量：");
	scanf("%d",&times);
	fp = fopen("随机密码.txt","w");//创建文件 
	if(fp == NULL)
	{
		printf("无法创建文件");
		exit(0);//无法创建文件则退出 
	}
	else
	{
		system("cls");
		printf("密码生成中...\n");
	}
	switch(choose)
	{
		case 1:	num(); break;
		case 2:	litter(); break;
		case 3:	charactor(); break;
		case 4: num_litter(); break;
		case 5: num_charactor(); break;
		case 6: litter_charactor(); break;
		case 7: num_litter_charactor(); break;
	}
	fclose(fp);
	system("cls");
	printf("任务完成！");
	system("pause");
	return 0; 
}

num()//密码只有数字 
{
	srand(time(NULL));
	char a[len];
	while(n < times)
	{
		for(i = 0; i < len; i++)
		{
			a[i] = rand()%10 + 48;
		}
		a[i] = '\0';
		fprintf(fp,"%s\n",a);
		n++;
	}
}

litter()//密码只有字母 
{
	srand(time(NULL));
	char a[len];
	while(n < times)
	{
		for(i = 0; i < len; i++)
		{
			a[i] = rand()%(122-97)+97;
		}
		a[i] = '\0';
		fprintf(fp,"%s\n",a);
		n++;
	}
}

charactor()//密码只有符号 
{
	srand(time(NULL));
	char a[len];
	while(n < times)
	{
		for(i = 0; i < len; i++)
		{
			if(!flag)
				a[i] = original[rand()%14];
			else
				a[i] = _new[rand()%new_len];
		}
		a[i] = '\0';
		fprintf(fp,"%s\n",a);
		n++;
	}
}

num_litter()//密码有数字.字母 
{
	srand(time(NULL));
	char a[len];
	while(n < times)
	{
		for(i = 0; i < len; i++)
		{
			if(rand()%2 == 1)
				a[i] = rand()%10 + 48;
			else
				a[i] = rand()%(122-97)+97;
		}
		a[i] = '\0';
		fprintf(fp,"%s\n",a);
		n++;
	}
}

num_charactor()//密码只有数字和字符 
{
	srand(time(NULL));
	char a[len];
	while(n < times)
	{
		for(i = 0; i < len; i++)
		{
			if(rand()%2 == 1)
				a[i] = rand()%10 + 48;
			else
			{
				if(!flag)
					a[i] = original[rand()%14];
				else
					a[i] = _new[rand()%new_len];
			}
		}
		a[i] = '\0';
		fprintf(fp,"%s\n",a);
		n++;
	}
}

litter_charactor()//密码有字母和字符 
{
	srand(time(NULL));
	char a[len];
	while(n < times)
	{
		for(i = 0; i < len; i++)
		{
			if(rand()%2 == 1)
				a[i] = rand()%(122-97)+97;
			else
			{
				if(!flag)
					a[i] = original[rand()%14];
				else
					a[i] = _new[rand()%new_len];
			}
		}
		a[i] = '\0';
		fprintf(fp,"%s\n",a);
		n++;
	}
}

num_litter_charactor()//密码有字母。数字。字符 
{
	srand(time(NULL));
	char a[len];
	while(n < times)
	{
		for(i = 0; i < len; i++)
		{
			if(rand()%3 == 0)
				a[i] = rand()%10 + 48;
			else if(rand()%3 == 1)
				a[i] = rand()%(122-97)+97;
			else
			{
				if(!flag)
					a[i] = original[rand()%14];
				else
					a[i] = _new[rand()%new_len];
			}
		}
		a[i] = '\0';
		fprintf(fp,"%s\n",a);
		n++;
	}
}
