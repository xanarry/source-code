#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, total_v;
    int v[100];
    int p[100];
    cin >> n >> total_v;//输入物件数量和背包总体积
    for (int i = 1; i <= n; i++) 
        cin >> v[i];//输入每件物品的体积
    for (int i = 1; i <= n; i++) 
        cin >> p[i];//输入每件物品的价值

    int dp[100][100];
    memset(dp, 0, sizeof(dp));//初始化
    //动态规划
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= total_v; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i - 1][j - v[i]] + p[i], dp[i - 1][j]);
        }
    }
    cout << "max_v = " << dp[n][total_v] << endl;//输出最大价值
    return 0;
}
