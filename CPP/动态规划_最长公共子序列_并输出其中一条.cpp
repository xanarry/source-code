#include <iostream>
#include <string>
using namespace std;

int dp[100][100];
string a, b;

void track(int i, int j)
{
    if (i <= 0 || j <= 0)
        return;
    if (a[i - 1] == b[j - 1])
    {
        track(i - 1, j - 1);
        cout << a[i - 1];
    }
    else if (dp[i][j - 1] >= dp[i - 1][j])
        track(i, j - 1);
    else
        track(i - 1, j);
}

int lcs(string a, string b)
{
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[a.length()][b.length()];
}


int main(int argc, char const *argv[])
{
    a = "bdcaba";
    b = "abcbdab";
    //cin >> a >> b;
    int len = lcs(a, b);
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << len << endl;
    track(a.length(), b.length());
    cout << endl;
    return 0;
}

/*
a = "bdcaba";
b = "abcbdab";

    0 1 2 3 4 5 6
    a b c b d a b
0 b 0 1 1 1 1 1 1
1 d 0 1 1 1 2 2 2
2 c 0 1 2 2 2 2 2
3 a 1 1 2 2 2 3 3
4 b 1 2 2 3 3 3 4
5 a 1 2 2 3 3 4 4

4
bcba
*/