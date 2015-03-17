/*如果我们有面值为1元、3元和5元的硬币若干枚，用最少的硬币分别凑够1-100元，输出对应的最小的硬币数*/
#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    int dp[105];
    memset(dp, 101, sizeof(dp));//初始化一个很大的值
    int cov[] = {1, 3, 5};//定义硬币面额的类型
    dp[0] = 0;//设定初始化条件，即换0元的时候肯定只需要0个硬币
    const int N = 100;//定义最大计算到100
    for (int i = 0; i <= N; i++)//遍历0-100元
    {
        for (int j = 0; j < 3; j++)//遍历三种面值的硬币，从中找到最小的
        {
            if (i >= cov[j])//只有当前需要计算的货币比1,3,5大，才需要执行这样的计算，同时防止负数下标出现
                dp[i] = min(dp[i - cov[j]] + 1, dp[i]);//第i块钱最小的硬币个数肯定是在第i-cov[j]块钱的基础上加上1个面值为cov[j]的硬币构成的
        }
    }
    for (int i = 0; i <= N; i++)
        cout << i << ": " << dp[i] << endl;
    return 0;
}
