#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int main(void)
{
    srand(time(NULL));		//������������ӣ�û�����Ļ�ÿ�κ�����һ������
    int a,b,n,i;
    a = 1, b = 150;
    n = rand()%(b-a)+a; //���ڲ���[a,b]�������

    for (i = 0; i < 100; i++)
    {
        printf("���˹��ڣ�%02d", rand()%(b-a)+a);
        system("cls");
    }
    printf("���˹��ڣ�%02d", rand()%(b-a)+a);
    system("pause>nul");
}
