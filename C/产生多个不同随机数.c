#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 150//���ֵ150
#define MIN 1//��Сֵ1
#define N 10//����10����ͬ�������ע��������ĸ������ܳ��������С��֮��ķ�Χ����Ȼ�ᵼ����ѭ��

int main()
{
	srand(time(NULL));
    int RandNum, a[N] = {0};
    int i, j, flag = 0, t=0;
    while(1)
    {
    	flag = 0;
    	if(t == N)
    		break;
    		
		RandNum = (rand()%(MAX - MIN)) + MIN;
		for(i = 0; i < t; i++)
		{
			if(a[i] == RandNum)
				flag = 1;
		}
		if(flag != 1)
		{
			a[t] = RandNum;
			printf("��%2d����: %d\n",t+1,a[t]);
			t++;
		}	
	}	
	system("PAUSE > NUL");
    return 0;
}
