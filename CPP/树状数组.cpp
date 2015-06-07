#include <iostream>
using namespace std;

const int maxlen = 10;

int a[maxlen + 1];
int bit[maxlen + 1];

int lowbit(int n)
{
    return n & (-n);
}

void build()
{//建立树状数组从前向后,前面是后面的基础
    for (int i = 1; i <= maxlen; i++)
    {
        bit[i] = a[i];
        for (int j = i - 1; j > i - lowbit(i); j -= lowbit(j))
            bit[i] += bit[j];
    }
}

void edit(int i, int new_v)
{//更新值从前向后
    int inc = new_v - a[i];
    a[i] = new_v;
    for (int j = i; j <= maxlen; j += lowbit(j))
        bit[j] += inc;
}

int sum(int n)
{//求和从后向前
    int ans = 0;
    for (int i = n; i > 0; i -= lowbit(i))
        ans += bit[i];
    return ans;
}

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= maxlen; i++)
        a[i + 1] = i + 1;
    build();
    for (int i = 1; i <= 10; i++)
        cout << sum(i) << endl;
    return 0;
}