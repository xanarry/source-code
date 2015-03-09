#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	int i,j,n,a[10];
	scanf("%d",&n);
	for(j = 0; j < n; j++)
	{ 
	    scanf("%s",s);
	    for(i = 0; i < strlen(s)/2; i++)
		{
		    if(s[i] != s[strlen(s)-i-1])
			{
			   a[j] = 0;
			   break;
   		    }
	        a[j] = 1;
		}
	} 
    for(i = 0; i < n-1; i++)
	{
    	if(a[i] == 1)
			printf("YES\n");
    	if(a[i] == 0)
			printf("NO\n");
    }
        if(a[n-1] == 1)
			printf("YES");
    	if(a[n-1] == 0)
			printf("NO");
	return 0;
}
