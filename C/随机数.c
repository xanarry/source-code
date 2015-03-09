#include<stdio.h> 
#include<time.h> 
int main(void)
{
	int a,b,c;
	srand(time(NULL));		//使用函数以毫秒为单位生成随机数种子 
    a = rand()%10 + 1;			//产生随机数a 
    b = rand()%100 + 1; 		//产生随机数b
    printf("%d %d",a,b);
}
