/*********************************
���������ڽ���ҳ����������˵���Ŀ
*********************************/ 
#include <stdio.h>
#define A (b + c + d + e == 3)
#define B (a + c + d + e == 4)
#define C (a + b + d + e == 3)
#define D (a + b + c + e == 0)
//��ɫ��1��ʾ����ɫ��0��ʾ 

int main()
{
	int t[5] = {0};
	int a,b,c,d,e;
	int i;
	for(a = 0; a <= 1; a++)
	{
		for(b = 0; b <= 1; b++)
		{
			for(c = 0; c <= 1; c++)
			{
				for(d = 0; d <= 1; d++)
				{
					for(e = 0; e <= 1; e++)
					{
						if((!A && !B && C && D) || (A && !B && !C && D) || (A && B && !C && !D) || (!A && B && !C && D) || (!A && B && C && !D) || (A && !B && C && !D) || (A && B && !C && !D))
						{
							if(a) t[0]++;
							if(b) t[1]++;
							if(c) t[2]++;
							if(d) t[3]++;
							if(e) t[4]++;
						}
					//	printf("A=%d B=%d C=%d D=%d E=%d\n",a,b,c,d,e);	��������һ�����鿴���ڵ��������	
					}
				}
			}
		}
	}
	for(i = 0; i < 5; i++)
	{
		if(t[i] == 3)
		printf("%c",65+i);
	}
	//A�Ļ�
	//b + c + d + e = 3;
	//B�Ļ�
	//a + c + d + e = 4;
	//C�Ļ� 
	//a + b + d + e = 3;
	//D�Ļ� 
	//a + b + c + e = 0;
	return 0;
}
