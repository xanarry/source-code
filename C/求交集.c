#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5,6,7,8,9,10,-1};//-1作为终止标志 
	int b[] = {2,4,9,-1};
	int flag = getConjunction(a, b);
	printf("\n交集数量是%d\n", flag);
	return 0;
}

int getConjunction(int *a, int *b)
{
	int i = 0, j = 0;
	int k = 0;
	int c[20];

	while (a[i] != -1 && b[j] != -1)
	{
		if (a[i] == b[j])
		{
			c[k++] = a[i];
			i++;
			j++;
		}
		else if (a[i] < b[j])
			i++;
		else
			j++;
	}
	c[k] = -1;
	
	if (k == 0)
		return -1;
	else
	{
		k = 0;
		while (c[k] != -1)
		{
			printf("%d ", c[k]);
			k++;
		}
		return k;
	}
}