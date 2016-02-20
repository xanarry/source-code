#include <iostream>
#include <algorithm>
using namespace std;

/*
输入要换取的钱的数量, 和硬币的类型, 输出最少要多少枚硬币能搞定
*/
int v[1000];
int main(int argc, char const *argv[])
{
    int n, m, types[10];
    cin >> n >> m;//cash value and coin types
    for (int i = 0; i < m; i++)
        cin >> types[i];

    for (int i = 1; i <= n; i++)
    {
        v[i] = 0x7FFFFFF;
        for (int j = 0; j < m && i >= types[j]; j++)
            v[i] = min(v[i - types[j]] + 1, v[i]);
    }

    for (int i = 0; i <= n; i++)
        cout << i << " -> " << v[i] << endl;
    return 0;
}
/*
6 3
1 3 4

0 1 2 1 1 2 2
*/