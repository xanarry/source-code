#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(NULL));
	int a[10],i,j,k;
	int *p;							//定义指针变量指向数组a 
    for(p = a; p < a+10; p++)
    { 
    	*p = rand()%100+1;			//将随机数给p所指向的数组元素地址 
    } 
    for(i = 0; i < 10; i++)
    { 
    	printf("a[%d]=%d\n",i,a[i]);
    } 
    printf("\n--------------------------------\n"); 
    for(p = a; p < a+10; p++)
	printf("%d ",*p);				//通过指针输出元素 
    return 0;
 }
 
