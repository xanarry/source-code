#include <iostream>
#define BIT_4 0xF
#define BIT_8 0xFF
#define BIT_16 0xFFFF
#define BIT_32 0xFFFFFFFF
#define BIT_64 0xFFFFFFFFFFFFFFFF
using namespace std;

int main ()
{
    //原理是一个的二进制与一位二进制全为1的数去或运算, 因为是低位对齐运算
    //最后结果如果全是1的话即十进制-1, 那么位数正好是给定的二进制的位数
    int a = 1, res[5];
    res[0] = a | BIT_4;
    res[1] = a | BIT_8;
    res[2] = a | BIT_16;
    res[3] = a | BIT_32;
    res[4] = a | BIT_64;

    int i;
    for (i = 0; i < 5; i++)
        if (res[i] == -1)
            break;
    if (i == 0)
        cout << "4 bit" << endl;
    else if (i == 1)
        cout << "8 bit" << endl;
    else if (i == 2)
        cout << "16 bit" << endl;
    else if (i == 3)
        cout << "32 bit" << endl;
    else if (i == 4)
        cout << "64 bit" << endl;
    else
        cout << "more than 64 bit" << endl;
    return 0;
}