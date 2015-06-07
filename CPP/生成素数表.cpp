#include <iostream>
#include <cmath>
#include <cstring>
#define MAX 350000000
using namespace std;

bool valid[MAX];
int prime[MAX];

void getprime(int n, int &tot, int ans[])
{
    int i,j;
    memset(valid, true, sizeof(valid));
    for(i = 2; i <= n; i++)
    {
        if(valid[i])
        {
            tot++;
            ans[tot]=i;
        }

        for(j = 1; (j <= tot) && (i * ans[j] <= n); j++)
        {
            valid[i * ans[j]] = false;
            if(i % ans[j] == 0)
                break;
        }
    }    
}

int main()
{
    int i,n,sum = 0;
    cin>>n;
    //此函数生成n以内所有素数保存到prime数组,素数个数保存到变量sum
    getprime(n,sum,prime);
    
    for(i = 1; i <= sum; i++)
        cout << prime[i] << endl;
    return 0;
}