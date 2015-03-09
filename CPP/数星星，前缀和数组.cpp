#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;
const int maxn=1200;
int a[maxn][maxn]={0};
int i,j,n,m,p;
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            int w;
            scanf("%d",&w);
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+w;
        }
    }
    for (i=1;i<=p;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]);
    }
    return 0;
}

