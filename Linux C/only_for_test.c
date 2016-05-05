#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
int len[100005];
int a[100005];

int main()
{
    //freopen ("in.txt", "wr", stdin);
    //freopen ("out.txt","w",stdout);
    int n, maxl = 0;
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        len[a[i]] = MAX(len[a[i]], len[a[i] - 1] + 1);
        if (len[a[i]] > maxl)
            maxl = len[a[i]];
    }
    printf("%d\n", maxl);
    return 0;
}