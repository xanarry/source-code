#include<stdio.h>
int main()
{
	int n,i;
 	long long s=1;
 	printf("input n!, n=");
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
 	{ 
    	s=s*i;			//ʹ��ѭ��ʵ�ֽ׳ˣ�ÿ��i�Լ�1��ֱ�� i == n 
	}
 	printf("n!=%d\n",s);
 	return 0;
}
