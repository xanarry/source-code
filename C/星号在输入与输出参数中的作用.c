#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[100] = "default";
    int a = 0;

    //输入语句中使用*相当于跳过一个输入, 对于含有*的输入控制, 不需要设置变量接收输入
    scanf("%*s %d", &a);
    printf("%s, %d\n", str, a);

    double b = 12.4567;
    int width = 10;
    int fp = 2;
    //在输出语句中使用*相当与一个动态控制输出宽度的参数, 控制符符中一个*对应着一个控制变量
    printf("%*.*f\n", width, fp, b);
    return 0;
}
