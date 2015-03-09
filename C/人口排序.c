#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)     
{
	if(strlen((char *)b) > strlen((char *)a)) return 1;
	if(strlen((char *)b) < strlen((char *)a)) return 0;
	if(strlen((char*)a)==strlen((char*)b))
	{
        if(strcmp((char*)a,(char*)b)==0) return 0;
        if(strcmp((char*)a,(char*)b)<0) return 1;
        if(strcmp((char*)a,(char*)b)>0) return -1;//设定如果字符串的长度相同，则按字典序比较数字 
    }
}
char a[100010][10010];
int main()
{
	
	int i,n,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n-1;i++)
	{
		printf("%s",a[i]);
		printf("\n");
	}
	printf("%s",a[n-1]);
	return 0;
}
	
