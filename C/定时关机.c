#include <stdio.h>
#include <windows.h>

int main()
{
	int t;
	int choose;
	printf("+---------------------+\n");
	printf("| 1: 10分钟后关机     |\n");
	printf("| 2: 20分钟后关机     |\n");
	printf("| 3: 30分钟后关机     |\n");
	printf("| 4: 40分钟后关机     |\n");
	printf("| 5: 50分钟后关机     |\n"); 
	printf("| 6: 一个小时后关机   |\n");
	printf("| 7: 一个半小时后关机 |\n");
	printf("| 8: 两个小时后关机   |\n");
	printf("| 0: 取消定时关机     |\n");
	printf("+---------------------+\n");
	printf("请键入您的选择：");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1 :	system("shutdown -s -t 600"); break;
		case 2 :	system("shutdown -s -t 1200"); break;
		case 3 :	system("shutdown -s -t 1800"); break;
		case 4 :	system("shutdown -s -t 2400"); break;
		case 5 :	system("shutdown -s -t 3000"); break;
		case 6 :	system("shutdown -s -t 3600"); break;
		case 7 :	system("shutdown -s -t 5400"); break;	
		case 8 :	system("shutdown -s -t 7200"); break;
		case 0 :	system("shutdown -a"); break;
	}
	system("pause");
	return 0;
}
