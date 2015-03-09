#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    char b[100];
    printf("input 2 string\n");
    scanf("%s", a);
    scanf("%s", b);
    strlen(a) > strlen(b) ? printf("%s\n", a) : printf("%s\n", b);
}