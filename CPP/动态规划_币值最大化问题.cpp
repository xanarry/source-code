#include <iostream>
#include <algorithm>
using namespace std;

/*给定一排面值不定的硬币, 如何选择硬币在互不相邻的情况下, 使得取出的硬币面值最大*/

int main(int argc, char const *argv[])
{
    int n, c[100], v[100];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    v[0] = 0;
    v[1] = c[1];

    for (int i = 2; i <= n; i++)
        v[i] = max(c[i] + v[i - 2], v[i - 1]);

    for (int i = 1; i <= n; i++)cout << v[i] << " ";
    return 0;
}
/*
6
5 1 2 10 6 2
17
*/