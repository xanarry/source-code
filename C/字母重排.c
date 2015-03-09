#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return ( *(char *)a - *(char *)b );
}
int main()
{
    char str[1125];
    int i = 0;
    int t= 0;
    char c[1125];
    gets(c);
    for(i = 0; i < strlen(c); i++)
    {
        if(islower(c[i])) str[t++] = c[i];
    }
    qsort(str,strlen(str),sizeof(char),cmp);
    puts(str);
    return 0;
}
