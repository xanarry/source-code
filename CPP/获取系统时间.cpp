#include <iostream>
#include <cstdio>
#include <ctime>

int main()
{
    time_t t = time(0);
    char tmp[200];
    strftime(tmp, sizeof(tmp), "������%c",localtime(&t));
    printf("%s\n", tmp);
    return 0;
}
