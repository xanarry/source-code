#include <iostream>
#include <algorithm>
using namespace std;

int dp[20000];
int main(int argc, char const *argv[])
{
    int m, n, v[3500], w[3500];
    cin >> n >> m;//n->types m->capacity
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];//each material's volume and weight
    
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[m] << endl;
    return 0;
}

/*
3 10
3 4
4 6
5 7
*/