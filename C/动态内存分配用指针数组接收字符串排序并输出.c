#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sort(char *p[], int num)
{
	int i,j,k;
	char *t;
	for(i=0;i<num-1;i++)
	{
		k=i;
		for(j=i+1;j<num;j++)
		{
			if(strcmp(p[j],p[k])<0)
			k = j;
		}
		if(k!=i)
		{
			t=p[i];
			p[i]=p[k];
			p[k]=t;
		}
			
	}
}
int main()
{
	int n;
	int i;
	int j;
	printf("how many string u wanna input:\n");
	scanf("%d",&n);
	char *a[n];
	printf("please input %d strings\n",n);
	for(i=0;i<n;i++)
	{
		a[i]=(char *)malloc(sizeof(char)*30);
		scanf("%s",a[i]);
	}
	printf("\nafter sort it's:\n");
	sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
		free(a[i]);
	}
	return 0;
}
