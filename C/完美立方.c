#include<stdio.h>
int main()
{
	int n;
	int a,b,c,d;
	int i,f = 1;
	scanf("%d",&n);
	for(i = 2; i <= n; i++)
	{
		a = i;
		for(b = 2; b < a; b++)
		{
			for(c = b; c < a; c++)
			{
				for(d = c; d < a; d++)
				{
					if((a*a*a == (b*b*b + c*c*c + d*d*d))) 	//完美立方的条件 
					{
						if(f == 0) 
							printf("\nCube = %d, Triple = (%d,%d,%d)",a,b,c,d);
						if(f == 1)
						{
							printf("Cube = %d, Triple = (%d,%d,%d)",a,b,c,d);
							f=0;
						}
					}
				}
			}
		}
	}
	return 0;
}
