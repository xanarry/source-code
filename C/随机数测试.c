#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    srand(time(NULL));		//������������ӣ�û�����Ļ�ÿ�κ�����һ������
    int a,b,n,i;
    scanf("%d %d",&a,&b);
    printf("%02d", )
    for(i = 0; i < 10000; i++)
    {
        n = rand()%(b-a)+a;	//���ڲ���[a,b]�������
        printf("%d",n);
        printf("\n");
    }
}
