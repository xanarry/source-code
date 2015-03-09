#include<stdio.h>
int main()
{
	int m,n,t,r,k;
	scanf("%d%d",&m,&n);		//m>=n才能做计算
	k = m*n;
	if(m < n)
	{
		t = m;
    	m = n;
		n = t;
    }							//如果n<m则交换两个数 
	while(m%n != 0) 
	{
		r = m%n;  
		m = n;
		n = r;					//不断替换计算 
	}
	printf("最大公约数是%d\n最小公倍数是%d",n,k/n);
	return 0;
}
