#include <stdio.h>
#include <string.h>

//实现域名的字段顺序翻转函数,比如输入www.so.me, 输出为com.so.www, 要求实现的效率尽可能的优化
void trans(char *res, char *a)
{
    strcat(a, ".");
    const char *src = a;
    int len = strlen(src) - 1;
    int i = len;
    while(src[--i] != '.');
    
    memcpy(res, src + i + 1, (len - i) * sizeof(char));
    memcpy(res + (len - i), src + 4, (i - 3) * sizeof(char));
    memcpy(res + (len + 1 - 4), src, 3 * sizeof(char));
    res[len] = '\0';
}

int main()
{
    char a[100], res[100];
    scanf("%s", a);
    trans(res, a);
    puts(res);
    return 0;
}

