#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char a[] = "www.so.com";
    char res[100];
    int s = strlen(a) - 1;
    for (int i = strlen(a) - 1; i >= 0; i--)
    {
        if (a[i] == '.')
        {
            for (int j = i + 1; j <= s; j++)
                printf("%c", a[j]);
            printf("%c", '.');
            s = i - 1;
        }
    }
    for (int j = 0; j <= s; j++)
        printf("%c", a[j]);
    return 0;
}

