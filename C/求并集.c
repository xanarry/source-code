#include <stdio.h>
#define N 5
#define M 5

int main(int argc, char const *argv[])
{
	int i, j, k;
	int a[N], b[M], c[N + M];
	printf("input array a\n");
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}

	printf("input array b\n");
	for (i = 0; i < M; ++i)
	{
		scanf("%d", &b[i]);
	}

	printf("a[N] = {");
	for (i = 0; i < N; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("}\n");

	printf("B[M] = {");
	for (i = 0; i < M; ++i)
	{
		printf("%d ", b[i]);
	}
	printf("}\n");

	for (i = 0; i < N; i++)
	{
		c[i] = a[i];
	}

	k = N;
	for (j = 0; j < M; j++)
	{
		for (i = 0; i < N; i++)
		{
			if (b[j] == a[i])
				break;
			
		}
		if (i == N)
		{
			c[k] = b[j];
			k++;
		}
	}

	printf("C[ ] = {");
	for (i = 0; i < k; ++i)
	{
		printf("%d ", c[i]);
	}
	printf("}\n");
	return 0;
}
