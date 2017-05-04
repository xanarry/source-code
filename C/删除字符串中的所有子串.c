#include <stdio.h>

char *del_substr(char *str,char const *substr)
{
    if(*substr == '\0') return 0;
    char *copyPtr = NULL;//记录移动字符串片段起点的前一个位置, 默认第一个字符的前一个为NULL(从左向右)
    char *strStart = str;//记录原始字符串的起点指针

    while (1)
    {
        int matchLen = 0;//记录匹配长度
        //在字符串中搜索需要删除的部分
        for ( ; *str == *substr && *substr != '\0'; str++, substr++, matchLen++);
        //如果搜索到完整的子串则进行移动操作
        if (*substr == '\0')
        {
            //将前面的字符串移动到后面
            for (char *i = str - matchLen - 1; i >= strStart && i != copyPtr; i--)
                *(matchLen + i) = *i;
            //重新标记复制字符串的起点的前一个位置,第一次到匹配长度减一所在的位置, 后面没匹配一次都加上匹配长度
            copyPtr = (copyPtr == NULL ? strStart + matchLen - 1 : copyPtr + matchLen);
        } else
            str++;//如果没有匹配上完整字符串, 那么跳到原字符串的下一个字符串从新匹配
        //如果搜索到原字符串尾部, 结束匹配
        if (*str == '\0') break;
        substr -= matchLen;//还原目标串, 用与下次重新匹配
    }
    return copyPtr == NULL ? strStart : copyPtr + 1;
}

int main(int argc, char const *argv[])
{
    char s[]="aaabcdaacdaada";
    char b[]="aa";
    printf("%s\n", del_substr(s,b));
    return 0;
}
