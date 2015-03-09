#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000][26],b[26];
	int i,n,j;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%s",a[i]);
	}
	
	for(j = 0; j < n-1; j++)
	{
	   for(i = 0; i < n-j-1; i++)
	   {
			if( strcmp(a[i],a[i+1]) > 0)
			{
				strcpy(b,a[i+1]);
				strcpy(a[i+1],a[i]);
				strcpy(a[i],b);
			}
		}	//使用字符串比较函数，用冒泡排序排序 
	}
	for(i = 0; i < n-1; i++)
	{
		printf("%s",a[i]);
		printf("\n");
	}
	printf("%s",a[n-1]);
	return 0;
}
	
