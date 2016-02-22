#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1000], v[1000], w[1000], c[1000];
int index = 1;

void binary_separate(int tv, int tw, int tc)
{
    for (int i = 1; i <= tc; i <<= 1)
    {
        v[index] = i * tv;
        w[index++] = i * tw;
        tc -= i;
    }
    if (tc > 0)
    {
        v[index] = tc * tv;
        w[index++] = tc * tw;
    }
}

int main(int argc, char const *argv[])
{
    int m, n, tv, tw, tc;//m max capacity, n types of material
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tv >> tw >> tc;
        binary_separate(tv, tw, tc);
    }
    index--;
    
    for (int i = 1; i <= index; i++)
        for (int j = m; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[m] << endl;
    return 0;
}

/*
1
8 2
2 100 4
4 100 2
*/
