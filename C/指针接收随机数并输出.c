#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(NULL));
	int a[10],i,j,k;
	int *p;							//����ָ�����ָ������a 
    for(p = a; p < a+10; p++)
    { 
    	*p = rand()%100+1;			//���������p��ָ�������Ԫ�ص�ַ 
    } 
    for(i = 0; i < 10; i++)
    { 
    	printf("a[%d]=%d\n",i,a[i]);
    } 
    printf("\n--------------------------------\n"); 
    for(p = a; p < a+10; p++)
	printf("%d ",*p);				//ͨ��ָ�����Ԫ�� 
    return 0;
 }
 
