/*
一个数字三角形。 请编一个程序计算从顶至底的某处的一条路径，
使该路径所经过的数字的总和最大。每一步可沿左斜线向下或右斜线向下走；
1<三角形行数<25；三角形中的数字为整数<1000；

Input
第一行为N，表示有N行
后面N行表示三角形每条路的路径权

Output
路径所经过的数字的总和最大的答案

Sample
输入数据
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

输出数据
30
*/
//自顶向下计算
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int l, maxv = -1;
    int a[120][120];
    int dp[120][120] = {a[0][0]};
    cin >> l;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < i + 1; j++)
            cin >> a[i][j];
    
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (i == 0)
                dp[i][j] = a[0][0];
            else if (j == 0 || j == i)
            {
                if (j == 0)
                    dp[i][j] = dp[i-1][j] + a[i][j];
                else
                    dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            }
            else
                dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    //对底部一列元素求最大值
    for (int j = 0; j < l; j++)
        maxv = max(maxv, dp[l - 1][j]);

    cout << maxv << endl;
    return 0;
}
