#include <stdio.h>
#include <windows.h>

int main()
{
	int t;
	int choose;
	printf("+---------------------+\n");
	printf("| 1: 10���Ӻ�ػ�     |\n");
	printf("| 2: 20���Ӻ�ػ�     |\n");
	printf("| 3: 30���Ӻ�ػ�     |\n");
	printf("| 4: 40���Ӻ�ػ�     |\n");
	printf("| 5: 50���Ӻ�ػ�     |\n"); 
	printf("| 6: һ��Сʱ��ػ�   |\n");
	printf("| 7: һ����Сʱ��ػ� |\n");
	printf("| 8: ����Сʱ��ػ�   |\n");
	printf("| 0: ȡ����ʱ�ػ�     |\n");
	printf("+---------------------+\n");
	printf("���������ѡ��");
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
