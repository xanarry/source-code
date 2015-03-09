#include<stdio.h>
int main()
{
	int a,b;
	int *pa, *pb;
	scanf("%d%d",&a,&b);
	if(a < b) pa = &b;
	printf("%d %d",a,b);
	printf("\n");
	printf("max=%d",*pa);
	return 0;
}
	
