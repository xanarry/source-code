#include<stdio.h>
int main(void)
{
	int a[10]={9,12,21,23,32,24,34,45,51,77},b[11],k,i,n;
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n------------------------------\ninput a num:");
	scanf("%d",&n);
	printf("您输入的的数是 %d\n",n);
	for(i = 0; i < 10; i++)
	{
		if(n < a[0])
		{
		  	b[0] = n;
		  	b[i+1] = a[i];
		}
		else if(n > a[9])
		{
			b[i] = a[i];
			b[10] = n;
		}
		else
		{
			if((n >= a[i]) && (n <= a[i+1]))
			{
				k = i+1; 
				for(i = 0; i < 10; i++)
				{
				    if(i < k)	b[i] = a[i];
				    b[k] = n;
				    b[i+1] = a[i];
				}
			}
		}
    }
    for(i = 0; i < 11; i++)
    printf("%d ",b[i]);
}

	
