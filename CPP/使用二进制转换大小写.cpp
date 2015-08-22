#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char low[] = "abcd";
    char upp[] = "WXYZ";
    const int len = 4;

    for (int i = 0; i < len; i++)
    {
        low[i] &= -33; 
        upp[i] |= 32;
    }

    //  大写二进制------ 小写的二进制
    //A 0100 0001 ------ a 0110 0001
    //B 0100 0010 ------ b 0110 0010
    //C 0100 0011 ------ c 0110 0011
    /*
    可以看出, 大写与小写的区别在于二进制的6,7位上, 其他位的值一样
    所以只需要改变这两位既可, 大写到小写将第6位置为1, 小写到大写将第7位置为1
    */

    cout << low << endl;
    cout << upp << endl;
    return 0;
}