#include <stdio.h>
#include <windows.h>

int main()
{
	int i;
	int t;
	printf("������ʱ��(��λΪ��):");
	scanf("%d",&t);
	system("cls");
	for(i = t; i >= 1; i--) 
	{
		printf("%d",i);
		Sleep(1000);
		system("cls");
	} 
	puts("ʱ���Ѿ���������");
	return 0;
}
