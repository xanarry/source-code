#include <stdio.h>
#include <math.h>
int main()
{
	int a,m,n,j;
	scanf("%d%d",&m,&n);
	j = pow(2,n%3);	//该计算有次规律 
	if(m+j > 7) 
		printf("%d",(m+j)%7);
	else 
		printf("%d",m+j);
	return 0;
}
