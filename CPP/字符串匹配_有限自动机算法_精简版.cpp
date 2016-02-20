#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    int t,i,j,m,n,d=256,x;
    char text[1000];
    char pat[1000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&text);
        scanf("%s",&pat);
        n=strlen(text);
        m=strlen(pat);
        int dfa[d][m+1]; /*since we have to find all occurrences we are using m+1 instead of m. this is done so as to continue searching even after 
                        dfa is in state m. for this we want for mth column to have states for every character possible. think it through..u'll get it*/
        memset(dfa,0,sizeof(dfa));

        dfa[pat[0]][0]=1;
        x=0;
        for(i=1;i<=m;i++)
        {
            for(j=0;j<d;j++)
                dfa[j][i]=dfa[j][x];

            dfa[pat[i]][i]=i+1;
            x=dfa[pat[i]][x];
        }
        
        i=0;
        j=0;
        while(i<n){
            j=dfa[text[i]][j];
            if(j==m){
                printf("Found at index %d\n",i-m+1);
            }
            ++i;
        }
        
    }
    return 0;
}