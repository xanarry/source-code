#include<stdio.h>
#include<string.h>
int cmp(const void * a, const void * b)
{
    return *(char *)a - *(char *)b;
}
char a[1000000][3];
int main()
{
	int n,i,j,t=1;
	char b[1000010];//定义数组b记录已经复值的元素 
    b[0]='a';
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
		for(j=0;j<t;j++)
		{
			if(a[i][2]==b[j])
			{
				b[t]=a[i][0];//将新被赋值的变量记录于数组中 
				t++;
			}	
		}
	}
	if(t==1) printf("none");
	else
	{
		qsort(b,t,sizeof(b[1]),cmp);
	    for(i=1;i<t;i++)
		{
			printf("%c ",b[i]);
		}
	}	
	return 0;
}
