#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
 
 /*��Ϸ�з�����Ŀ¼�Ĳ�����Ϊ�Զ�*/
void guess();
int main()
{
	int choose;
	printf("\n  1   ������Ϸ\n");
	printf("\n  2   �˳���Ϸ\n");
	printf("---------------\n"); 
	printf("����������ѡ��"); 
	while(1)//ʹ��ѭ�������û��Ĵ������� 
	{
		scanf("%d",&choose);
		if((choose < 1) || (choose > 2))
		{
			system("cls");
			printf("\t��ʱû���ṩ����Ҫ��ѡ�������ѡ��!");
			Sleep(1000);
			system("cls");
			main();
		}	
		else 
			break;
	}
	switch(choose)
	{
		case(1):	system("cls"); guess(); break;//���ò����ֵĺ��� 
		default:	exit(0); break;
	}
	return 0;
	system("pause");
}

void guess()
{
	int t,juedui;
	int min;
	int max;
	int rand_num;
	int input;
	int count = 1; 
	int choose;
	srand(time(NULL));
	printf("��ѡ�����ַ�Χ��\n--------------------------\n");
	printf(" 100����û��˼�밴	1\n");
	printf(" 500����̫�����밴	2\n");
	printf("1000���ڲ������밴	3\n");
	printf("5000���ڲ�ˬ���밴	4\n");
	printf("�������ָ��̼��밴	5\n");
	printf(" �� �� �� �� �� ��	6\n");
	printf("--------------------------\nchoose:"); //���ѡ����Ŀ¼ 
	scanf("%d",&choose);
	printf("��ѡ�����%d\n",choose);
	
	if(choose == 6)
	{
		printf("��������Ҫ�µ����ַ�Χ�����������ÿո������");
		while(1)//ѭ�����ھ�������������� 
		{
			scanf("%d %d",&min,&max);
			if(min >= max)
			{
				system("cls");
				printf("������ĵ��������ֲ�������ѧ�߼������������룺");
			}	
			else 
				break;
		}
		system("cls");
		printf("\t\t���Ĳ²ⷶΧ��[%d,%d]",min,max);
		rand_num = rand()%(max - min) + min; 
	}
	
	if(choose == 1)
	{
		rand_num = rand()%100; 
	}
	
	if(choose == 2)
	{
		rand_num = rand()%500; 
	}
	
	if(choose == 3)
	{
		rand_num = rand()%1000; 
	}
	
	if(choose == 4)
	{
		rand_num = rand()%5000; 
	}
	
	if(choose == 5)
	{
		rand_num = rand(); 
	}
	
//	printf("%d",rand_num); //���д��빩����ʹ�� 

	Sleep(1000);
	system("cls");
	printf("\t\t��Ϸ��ʼ��");
	Sleep(1000);
	system("cls");
	
	printf("����������Ϊ����ȷ�����֣�");
	scanf("%d",&input);
	while(rand_num != input)//ѭ�������ж��û���������� 
	{
		t = (input - rand_num);
		count++; 
		if(count > 20)//��20��û�¶���ֱ�Ӹ�����ȷ�� 
		{
			printf("���˰ɣ������%d��û�в³�������������ȷ������%d",count-1,rand_num); 
			Sleep(7000);
			printf("��̫���ˣ�����һ����������");
			system("cls");
			main(); 
		} 
		
		if(t >= 1000)
		{
			printf("�����������Ҳ̫����,������ǧ����������ɣ�");
		}
		else if(t >= 100)
		{
			printf("����������ֺܴ�Ӵ��");
		}
		else if(t >= 50)
		{
			printf("�����������ƫ��Ӵ��������ֵ���Ǻܴ���");
		}
		else if(t >= 10)
		{
			printf("����ƫ��!������ȷ���ֲ�����λ���ˣ����Լ��ѣ�");
		}
		else if(t >= 5)
		{
			printf("������ˣ���С���");
		} 
		else if(t >= 1)
		{
			printf("�����С��ôһ������ȷ�ˣ��ٺ٣�");
		}
		else if(t >= -1)
		{
			printf("����ٴ���ôһ������ȷ��");
		}
		else if(t >= -5)
		{
			printf("�����������ƫСӴ��������ֵ���Ǻܴ���");
		}
		else if(t >= -10)
		{
			printf("�����������ƫСӴ!���Ǻܽӽ�����ȷ�����ˣ����Լ��ѣ�");
		}
		else if(t >= -50)
		{
			printf("������ˣ��ٴ���");
		} 
		else if(t >= -100)
		{
			printf("����ڴ�ʮ����ȷ�ˣ��ٺ٣�");
		}
		else if(t > -1000)
		{
			printf("�����������Ҳ̫С��,��С����λ���ˣ���������ɣ�");
		}
		else
		{
			printf("�����Ѿ�С�ò�ֵ������λ���ˣ�");
		}
		scanf("%d",&input);
	}
	
	if(count == 1)//���������ж����ڸ��ݲ�ͬ�Ĵ��������ͬ�Ľ�� 
	{
		printf("��̫�����ˣ�һ���Ը㶨�ˣ���ȷ���־���%d\n",rand_num);
		printf("���ڷ�����Ŀ¼��please wait!");
		Sleep(7000);
		system("cls");
		main();
	}
	
	if(count > 1 && count < 7)
	{
		printf("������%d�ξͰ���ȷ����%d�³����ˣ�\n",count,rand_num);
		printf("���ڷ�����Ŀ¼��please wait!");
		Sleep(7000);
		system("cls");
		main();
	}
	
	if(count > 7)
	{
		printf("Ŀ��Ч�ʱȽϵ��£�������%d�βŲ³���%d\n",count,rand_num);
		printf("���ڷ�����Ŀ¼��please wait!");
		Sleep(7000);
		system("cls");
		main();	
	} 
}
