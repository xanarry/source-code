#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

	/*ȫ�ֱ���*/ 
int len;//�û��趨���볤�� 
int new_len;//�����ַ�������ַ����鳤�� 
int times;//������������ 
int i;//ѭ��ʹ�� 
int n = 0;//������ 
int flag = 0;//0��ʾʹ��Ĭ���ַ��� 
FILE *fp;//�ļ�ָ�룬д���ݵ��ļ� 
char _new[100];//�û��Զ����ַ��� 
char original[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '=', '+'};//Ĭ���ַ��� 

int main()
{
	int choose; //��һ��ѡ�� 
	int choose1;//�ڶ���ѡ�� 
	int i;
	printf("--------------------\n");
	printf("1 ֻ������\n");
	printf("2 ֻ����ĸ\n");
	printf("3 ֻ�з���\n");
	printf("4 ����+��ĸ\n");
	printf("5 ����+����\n");
	printf("6 ��ĸ+����\n");
	printf("7 ����+��ĸ+����\n");
	printf("--------------------\n");//���Ŀ¼�б� 
	
	printf("��ѡ��");
	scanf("%d",&choose);
	
	if(choose == 3 || choose == 5 || choose == 7 || choose == 6)//ѡ�������漰�ַ���ѯ�ʲ���Ĭ���ַ������Զ��� 
	{
		system("cls");
		printf("----------------------\n"); 
		printf("ʹ��ϵͳĬ�Ϸ����밴 0\n");
		printf("�Զ����밴 1\n");
		printf("----------------------\n"); 
		printf("choose��");
		scanf("%d",&choose1);
		if(choose1 == 1)	
		{
			system("cls");
			printf("��������Ҫ�������ַ�:\n");
			scanf("%s",_new);
			flag = 1;//��¼�Ƿ�����Զ���֧�� 
			new_len = strlen(_new);//��¼�ַ����� 
		}
	}
	printf("���������볤��:");
	scanf("%d",&len); 
	printf("��������������������");
	scanf("%d",&times);
	fp = fopen("�������.txt","w");//�����ļ� 
	if(fp == NULL)
	{
		printf("�޷������ļ�");
		exit(0);//�޷������ļ����˳� 
	}
	else
	{
		system("cls");
		printf("����������...\n");
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
	printf("������ɣ�");
	system("pause");
	return 0; 
}

num()//����ֻ������ 
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

litter()//����ֻ����ĸ 
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

charactor()//����ֻ�з��� 
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

num_litter()//����������.��ĸ 
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

num_charactor()//����ֻ�����ֺ��ַ� 
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

litter_charactor()//��������ĸ���ַ� 
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

num_litter_charactor()//��������ĸ�����֡��ַ� 
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
