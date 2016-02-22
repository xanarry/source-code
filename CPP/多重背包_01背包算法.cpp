#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1000][1000], v[1000], w[1000], c[1000];

int main(int argc, char const *argv[])
{
    int m, n;//m max capacity, n types of material
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> c[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= c[i]; k++)
                if (j >= k * v[i])
                    dp[i][j] = max(dp[i][j] ,dp[i - 1][j - k * v[i]] + k * w[i]);
    cout << dp[n][m] << endl;
    return 0;
}