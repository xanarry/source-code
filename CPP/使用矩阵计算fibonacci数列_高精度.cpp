#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
using namespace std;
const int NUMLEN = 100000;//最大能保存100000位长度的数

//将字符串形式的数字转换为整数数组
void trans(string ain, int *aout, string bin, int *bout, int &maxlen)
{
    int alen = ain.length(); 
    int blen = bin.length();
    maxlen = max(alen, blen);
    for (int i = alen - 1, index = NUMLEN; i >= 0; i--)
        aout[--index] = ain[i] - '0';
    for (int i = blen - 1, index = NUMLEN; i >= 0; i--)
        bout[--index] = bin[i] - '0';
}

//定义大整数加法运算
string bignum_plus(string a, string b)
{
    int an[NUMLEN];
    int bn[NUMLEN];
    memset(an, 0, sizeof(an));
    memset(bn, 0, sizeof(bn));
    int maxlen;
    trans(a, an, b, bn, maxlen);

    for (int i = NUMLEN - 1; i >= NUMLEN - maxlen; i--)
    {
        int temp = an[i] + bn[i];
        if (temp >= 10)
        {
            an[i - 1]++;
            an[i] = temp - 10;
        }
        else
            an[i] = temp;
    }

    int start = NUMLEN - maxlen;
    if (an[start - 1] != 0)
        start--;
    stringstream ss;
    for (int i = start; i < NUMLEN; i++)
        ss << an[i];
    return ss.str();
}

//定义大整数减法运算
string bignum_mult(string a, string b)
{
    int an[NUMLEN];
    int bn[NUMLEN];
    int result[NUMLEN];
    memset(an, 0, sizeof(an));
    memset(bn, 0, sizeof(bn));
    memset(result, 0, sizeof(bn));
    int maxlen;
    trans(a, an, b, bn, maxlen);

    for (int i = NUMLEN - 1; i >= NUMLEN - a.length(); i--)//遍历乘数A
    {
        for (int j = NUMLEN - 1; j >= NUMLEN - b.length(); j--)//遍历乘数B
        {
            int temp = an[i] * bn[j] + result[(i + j + 1) - NUMLEN];
            result[(i + j + 1) - NUMLEN] =  temp % 10;//取余数保存
            if (temp >= 10)//进位，错误相加同时进行
                result[(i + j + 1) - NUMLEN - 1] += temp / 10;
        }
    }
    int start = NUMLEN - a.length() - b.length() - 1;
    while (result[start] == 0)
        start++;

    stringstream ss;
    for (int i = start; i < NUMLEN; i++)
        ss << result[i];
    return ss.str();
}

struct MATRIX
{
    string a11, a12;
    string a21, a22;

    MATRIX(string a, string b, string c, string d) : a11(a), a12(b), a21(c), a22(d){}
    MATRIX() : a11("0"), a12("0"), a21("0"), a22("0"){}
};

MATRIX matrix_mult(MATRIX a, MATRIX b)
{
    MATRIX result;
    //将此处原有的运算符替换为函数计算
    result.a11 = bignum_plus(bignum_mult(a.a11, b.a11), bignum_mult(a.a12, b.a21));
    result.a12 = bignum_plus(bignum_mult(a.a11, b.a12), bignum_mult(a.a12, b.a22));
    result.a21 = bignum_plus(bignum_mult(a.a21, b.a11), bignum_mult(a.a22, b.a21));
    result.a22 = bignum_plus(bignum_mult(a.a21, b.a12), bignum_mult(a.a22, b.a22));
    return result;
}

MATRIX matrix_pow(MATRIX a, int n)
{
    MATRIX result;
    if (n == 1)
        result = a;
    else if (n % 2 == 0)
    {
        MATRIX temp = matrix_pow(a, n / 2);
        result = matrix_mult(temp, temp);
    }
    else
    {
        MATRIX temp = matrix_pow(a, (n - 1) / 2);
        result = matrix_mult(matrix_mult(temp, temp), MATRIX("1", "1", "1", "0"));
    }
    return result;
}

string fibonacci(int n)
{
    if (n <= 1)
        return "1";
    else
        return matrix_pow(MATRIX("1", "1", "1", "0"), n).a11;
}

string fibonacciNums[100001];
int main(int argc, char const *argv[])
{
    int n;
    cout << fibonacci(1000) << endl;
    cout << (double)clock() / CLOCKS_PER_SEC << endl;//输出本次计算所用时间
    return 0;

}