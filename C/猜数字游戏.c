#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
 
 /*游戏中返回主目录的操作均为自动*/
void guess();
int main()
{
	int choose;
	printf("\n  1   进入游戏\n");
	printf("\n  2   退出游戏\n");
	printf("---------------\n"); 
	printf("请输入您的选择："); 
	while(1)//使用循环纠正用户的错误输入 
	{
		scanf("%d",&choose);
		if((choose < 1) || (choose > 2))
		{
			system("cls");
			printf("\t暂时没有提供您想要的选项，请重新选择!");
			Sleep(1000);
			system("cls");
			main();
		}	
		else 
			break;
	}
	switch(choose)
	{
		case(1):	system("cls"); guess(); break;//调用猜数字的函数 
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
	printf("请选择数字范围：\n--------------------------\n");
	printf(" 100以内没意思请按	1\n");
	printf(" 500以内太弱智请按	2\n");
	printf("1000以内才正常请按	3\n");
	printf("5000以内才爽快请按	4\n");
	printf("任意数字更刺激请按	5\n");
	printf(" 手 动 输 入 请 按	6\n");
	printf("--------------------------\nchoose:"); //输出选择了目录 
	scanf("%d",&choose);
	printf("您选择的是%d\n",choose);
	
	if(choose == 6)
	{
		printf("请输入您要猜的数字范围，两个数字用空格隔开：");
		while(1)//循环用于纠正不合理的输入 
		{
			scanf("%d %d",&min,&max);
			if(min >= max)
			{
				system("cls");
				printf("您输入的的两个数字不符合数学逻辑！请重新输入：");
			}	
			else 
				break;
		}
		system("cls");
		printf("\t\t您的猜测范围是[%d,%d]",min,max);
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
	
//	printf("%d",rand_num); //此行代码供测试使用 

	Sleep(1000);
	system("cls");
	printf("\t\t游戏开始！");
	Sleep(1000);
	system("cls");
	
	printf("请输入您认为是正确的数字：");
	scanf("%d",&input);
	while(rand_num != input)//循环不断判断用户输入的数据 
	{
		t = (input - rand_num);
		count++; 
		if(count > 20)//猜20次没猜对则直接告诉真确答案 
		{
			printf("算了吧！看你猜%d还没有猜出来，告诉你正确数字是%d",count-1,rand_num); 
			Sleep(7000);
			printf("你太笨了，像猪一样！从来！");
			system("cls");
			main(); 
		} 
		
		if(t >= 1000)
		{
			printf("您输入的数字也太大了,多了上千，重新输入吧！");
		}
		else if(t >= 100)
		{
			printf("您输入的数字很大哟！");
		}
		else if(t >= 50)
		{
			printf("您输入的数字偏大哟！不过差值不是很大了");
		}
		else if(t >= 10)
		{
			printf("数字偏大!但离正确数字不到两位数了！再试几把！");
		}
		else if(t >= 5)
		{
			printf("很相近了，再小点吧");
		} 
		else if(t >= 1)
		{
			printf("如果再小那么一点点就正确了，嘿嘿！");
		}
		else if(t >= -1)
		{
			printf("如果再大那么一点点就正确了");
		}
		else if(t >= -5)
		{
			printf("您输入的数字偏小哟！不过差值不是很大了");
		}
		else if(t >= -10)
		{
			printf("您输入的数字偏小哟!但是很接近了正确数字了！再试几把！");
		}
		else if(t >= -50)
		{
			printf("很相近了，再大点吧");
		} 
		else if(t >= -100)
		{
			printf("如果在大几十就正确了，嘿嘿！");
		}
		else if(t > -1000)
		{
			printf("您输入的数字也太小了,都小到三位数了，重新输入吧！");
		}
		else
		{
			printf("数字已经小得差值都有四位数了！");
		}
		scanf("%d",&input);
	}
	
	if(count == 1)//下面三个判断用于根据不同的次数输出不同的结果 
	{
		printf("你太厉害了，一次性搞定了！正确数字就是%d\n",rand_num);
		printf("正在返回主目录！please wait!");
		Sleep(7000);
		system("cls");
		main();
	}
	
	if(count > 1 && count < 7)
	{
		printf("不错！才%d次就把正确数字%d猜出来了！\n",count,rand_num);
		printf("正在返回主目录！please wait!");
		Sleep(7000);
		system("cls");
		main();
	}
	
	if(count > 7)
	{
		printf("目测效率比较底下！都猜了%d次才猜出是%d\n",count,rand_num);
		printf("正在返回主目录！please wait!");
		Sleep(7000);
		system("cls");
		main();	
	} 
}
