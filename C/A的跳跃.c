#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	int i = 0, j = 0;
	for(i=0; i<13; ++i)
	{
		system("cls"); 		//ϵͳ���� 
		for(j=0; j<i; ++j)
		{
			printf("   ");	//����ո� 
		}
		printf("A");		//���A 
		Sleep(540);			//ϵͳ��ͣ540���� 
	}
   	//Sleep(500);
	return 0;
}

