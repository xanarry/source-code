#include <stdio.h>

int prime(int x);
int huiwen(int x);
int main()
{
	int i;
	int n;
	int t;
	int sum = 0;
	scanf("%d",&n);
	for(i = 11; i <= n; i++)
	{
		t =i;
		if(prime(t) && huiwen(t)) sum++;
	}
	printf("%d",sum);
	return 0;
}
int prime(int x)
{
	int i = 2;
	while(x%i != 0)
	i++;
	if(i < x) return 0;
	else return 1;	
}
int huiwen(int x)
{
	if(x < 100)
	{
		if(x/10 == x%10) return 1;
		else return 0;
	}
	if(x >= 100 && x < 1000)
	{
		if((x/100) == (x%10)) return 1;
		else return 0;
	}
}
