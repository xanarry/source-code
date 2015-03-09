#include <stdio.h>
#include <string.h>

void makeNext(const char P[],int next[])
{
    int q,k;
    int m = strlen(P);
    next[0] = 0;

    for (q = 1,k = 0; q < m; ++q)
    {
        while(k > 0 && P[q] != P[k])
            k = next[k-1];

        if (P[q] == P[k])
            k++;

        next[q] = k;
    }
}

int kmp(const char T[],const char P[],int next[])
{
    int n,m;
    int i,q;
    n = strlen(T);
    m = strlen(P);
    makeNext(P,next);

    for (i = 0,q = 0; i < n; ++i)
    {
        while(q > 0 && P[q] != T[i])
            q = next[q-1];

        if (P[q] == T[i])
            q++;

        if (q == m)
           printf("matched\n");
    }    
}

int main()
{
    int i;
    int next[20]={0};
    char T[] = "ababxbababcadfdsss";
    char P[] = "abx";
    kmp(T,P,next);

    return 0;
}