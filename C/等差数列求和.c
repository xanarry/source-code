#include<stdio.h>
int main()
{
    long a1,i,n;
    int d;
    long long sum = 0;
    scanf("%ld%d%ld",&a1,&d,&n);
    for(i = a1; i <= (a1+(n-1)*d); i += d) //�Ȳ�������͹�ʽ 
     {
         sum += i;
     }
     printf("%lld",sum);
     return 0;
}
