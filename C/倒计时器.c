#include <stdio.h>
#include <windows.h>

int main()
{
	int i;
	int t;
	printf("请输入时间(单位为秒):");
	scanf("%d",&t);
	system("cls");
	for(i = t; i >= 1; i--) 
	{
		printf("%d",i);
		Sleep(1000);
		system("cls");
	} 
	puts("时间已经结束！！");
	return 0;
}
