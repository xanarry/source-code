#include <iostream>
#include <algorithm>
using namespace std;

//物品的种类有限, 每件物品的数量没有上限, 但实际上每件物品只能取(int)(背包容量/物品体积)这么多
int dp[1000][1000];

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int v[1000], w[1000];
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= j / v[i]; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << dp[n][m] << endl;
    return 0;
}

/*
3 5
3 4
2 10
2 20
*/
