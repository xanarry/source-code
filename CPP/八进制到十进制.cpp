#include <stdio.h>
#include <string.h>

int main()
{
    int a,b;
    scanf("%d",&a);
    b = 0;
    int x = 1;
    while(a)
    {
        b += (a % 10) *x;
        x *= 8;
        a /= 10;
    }
    printf("%d\n",b);
    return 0;
}
