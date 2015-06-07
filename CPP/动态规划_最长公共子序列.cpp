#include <iostream>
#include <cstring>
#define MAXN 2010
using namespace std;
int dp[MAXN][MAXN];

int LCS(string a, string b)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < a.length(); i++)
        for (int j = 1; j < a.length(); j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[a.length() - 1][b.length() - 1];
}

int main()
{
    string x, y;
    cin >> x >> y;
    x = ' ' + x;// 1234
    y = ' ' + y;// 2345
    cout << LCS(x, y) << endl;
    return 0;
}