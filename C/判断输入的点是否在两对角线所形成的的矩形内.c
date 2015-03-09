#include<stdio.h>

sort(int *m,int *n)
{
	int t;
	{
		t=*m;
		*m=*n;
		*n=t;
	}
}
int main()
{
	int x1,y1;
	int x2,y2;
	int n,i,sum=0;
	int x,y;
	scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
	if(x1>x2)
	sort(&x1,&x2);
	if(y1>y2)
	sort(&y1,&y2);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		if( (x>=x1&&x<=x2) && (y>=y1&&y<=y2) )
		sum++;
	}
	printf("%d",sum);
	return 0;
}
