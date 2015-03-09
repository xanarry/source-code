#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 149
#define MIN 1

int main()
{
	int num,i,count = 0;
	srand(time(NULL));
	while(count <= 80)
	{
		num = rand()%(MAX - MIN) + MIN;
		system("cls");
		printf("幸运观众是:%3d号！",num);
		count++;
	}
	system("pause > nul");
	return 0;
}
