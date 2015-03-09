#include <stdio.h>
int max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int a,b,c;
	int (*p)(int, int);
	p = max;
	printf("input 2 nums:\n");
	scanf("%d%d",&a,&b);
	printf("%d",(*p)(a,b));//调用函数输出最大数 
	return 0;
}
