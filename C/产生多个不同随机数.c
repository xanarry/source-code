#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 150//最大值150
#define MIN 1//最小值1
#define N 10//产生10个不同随机数，注意随机数的个数不能超过最大最小数之间的范围，不然会导致死循环

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
			printf("第%2d个是: %d\n",t+1,a[t]);
			t++;
		}	
	}	
	system("PAUSE > NUL");
    return 0;
}
