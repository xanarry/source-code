#include <stdio.h>
#include <string.h>
#include <math.h>

int huiwen(int n)
{
    if(n<100 && n % 10 == n /10)   //��λ������λʮλ���
       return 1;
    if(n>=100 && n % 10 == n /100 )//��λ������λ��λ���
       return 1;
    return 0;
}
int isPrime(int n)
{
    if(n<2) return 0;
    int i,l;
    l=(int)sqrt((double)n);
    for(i = 2;i <= l;i++)
       if(n % i == 0) return 0;//������

    return 1; //����
}
int main()
{
    int i,n,sum=0;
    while( scanf("%d",&n)!= EOF )
    {
       sum=0;
       for(i=11;i<=n;i++)
         if( isPrime(i) && huiwen(i))
            sum++;

       printf("%d\n",sum);
    }

    return 0;
}
