#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	int i = 0, j = 0;
	for(i=0; i<13; ++i)
	{
		system("cls"); 		//系统清屏 
		for(j=0; j<i; ++j)
		{
			printf("   ");	//输出空格 
		}
		printf("A");		//输出A 
		Sleep(540);			//系统暂停540毫秒 
	}
   	//Sleep(500);
	return 0;
}

