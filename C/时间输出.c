#include <stdio.h>
#include <windows.h>
#include <conio.h>

struct Time
{
	int h;
	int m;
	int s;
	int ms;
}time;

int main()
{
	time.ms = 0;
	time.s = 0;
	time.m = 0;
	time.h = 0;
	while(!kbhit())
	{
		Sleep(10);
		if(time.ms == 99)
		{
			time.s += 1;
			if(time.s == 60)
			{
				time.m += 1;
				if(time.m == 59)
				{
					time.h += 1;
					time.m = 0;
				}
				time.s = 0;
			}
			time.ms = 0;
		}
		else 
		{
			time.ms += 1;
		}
		printf("%02d:%02d:%02d:%02d\n",time.h,time.m,time.s,time.ms);
	}
	system("pause");
	return 0;
}

