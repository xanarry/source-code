#include <stdio.h>
#include <windows.h>
#define N 10000000000
//ѭ��4000 0000 0000�����İ��ڴ����㣬���ֻ�ܾ�ȷ��Բ���ʵ�10λС��
int main()
{
	double PI;
	double i,t;
	int flag = 1;
	printf("���ڼ���...");
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
