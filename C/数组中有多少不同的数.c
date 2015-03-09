#include<stdio.h>
int main()
{
	int a[10], i, j, d = 1;
	
	printf("input 10 nums\n");
	scanf("%d", &a[0]);			//单独接收第一个 
	for(i = 1; i<10; i++,d++)	//每接收一个数，d加1 
	{
		scanf("%d", &a[i]);
		for(j = 0; j < i; j++)
		{
			if(a[i] == a[j])
			{
				d--;
				break; 			//发现与前面的已接受的数相同，d减1 
			}
		}
	}
	printf("%d\n", d);
}

