#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct MATRIX//定义结构体保存矩阵
{
    int a11, a12;//其中a11是需要的fibonacci数
    int a21, a22;
    MATRIX(int a, int b, int c, int d) : a11(a), a12(b), a21(c), a22(d){}//构造函数
    MATRIX() : a11(0), a12(0), a21(0), a22(0){}//默认构造函数
};

MATRIX matrix_mult(MATRIX a, MATRIX b)//定义矩阵乘法运算
{
    MATRIX result;
    result.a11 = a.a11 * b.a11 + a.a12 * b.a21;
    result.a12 = a.a11 * b.a12 + a.a12 * b.a22;
    result.a21 = a.a21 * b.a11 + a.a22 * b.a21;
    result.a22 = a.a21 * b.a12 + a.a22 * b.a22;
    return result;
}

MATRIX matrix_pow(MATRIX a, int n)//定义矩阵次方运算，递归操作
{
    MATRIX result;
    if (n == 1)
        result = a;
    else if (n % 2 == 0)//如果是偶数次方
    {
        MATRIX temp = matrix_pow(a, n / 2);//次方折半计算
        result = matrix_mult(temp, temp);//将两个折半计算的结果相乘得到最终结果
    }
    else//如果是技术次方
    {
        MATRIX temp = matrix_pow(a, (n - 1) / 2);//少乘一个矩阵转为偶数次方计算，在最后结果中在乘一个矩阵即可
        result = matrix_mult(matrix_mult(temp, temp), MATRIX(1, 1, 1, 0));//乘上上一行代码没有乘的矩阵
    }
    return result;
}

unsigned fibonacci(int n)//定义fibonacci数列计算
{
    if (n <= 1)//起点是从0开始的，所有这里的条件是1
        return 1;
    else
        return matrix_pow(MATRIX(1, 1, 1, 0), n).a11;//计算矩阵的n次方
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << n << " : " << fibonacci(n - 1) << endl;
    return 0;
}