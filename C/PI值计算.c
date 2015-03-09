#include <stdio.h>
#include <windows.h>
#define N 10000000000
//循环4000 0000 0000，即四百亿次运算，结果只能精确到圆周率的10位小数
int main()
{
	double PI;
	double i,t;
	int flag = 1;
	printf("正在计算...");
	for(i = 1; i <= N*8; i += 2)
	{
		t = 1/i;
		t = t*flag;
		PI += t;
		flag = flag*-1;
	}
	system("cls");
	printf("PI=%.11f\n",4*PI);
	system("pause");
	return 0;
}
