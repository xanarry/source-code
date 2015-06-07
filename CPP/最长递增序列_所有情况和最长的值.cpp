#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string a;
    cin >> a;
    int dp[100];
    int maxlen = 1;
    for (int i = 0; i < a.length(); i++)
    {
        dp[i] = 1;//初始化的长度为1,即字符本身
        for (int j = 0; j < i - 1; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
                maxlen = max(dp[i], maxlen);
            }
        }
    }

    for (int i = 0; i < a.length(); i++)
        cout << a[i] << " " << dp[i] << endl;
    cout << "maxlen: " << maxlen << endl;
    return 0;
}

/*
72435183
11223143
*/