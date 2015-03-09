#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int main(void)
{
    srand(time(NULL));		//产生随机数种子，没有这句的话每次后会产生一样的数
    int a,b,n,i;
    a = 1, b = 150;
    n = rand()%(b-a)+a; //用于产生[a,b]的随机数

    for (i = 0; i < 100; i++)
    {
        printf("幸运观众：%02d", rand()%(b-a)+a);
        system("cls");
    }
    printf("幸运观众：%02d", rand()%(b-a)+a);
    system("pause>nul");
}
