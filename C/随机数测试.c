#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    srand(time(NULL));		//产生随机数种子，没有这句的话每次后会产生一样的数
    int a,b,n,i;
    scanf("%d %d",&a,&b);
    printf("%02d", )
    for(i = 0; i < 10000; i++)
    {
        n = rand()%(b-a)+a;	//用于产生[a,b]的随机数
        printf("%d",n);
        printf("\n");
    }
}
