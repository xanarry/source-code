#include<stdio.h>

int judge(int n)
{
	int i=2;
	while(n%i!=0) i++;
	if(i==n) return 1;
	else return 0;
}
int main()
{
	int n,a;
	int i,j;
	int t;
	int b[1000];
	scanf("%d",&n);    //����Ҫ�������ֵĸ��� 
	for(i=0,j=0;i<n;i++)
	{
		scanf("%d",&a);
		if(judge(a))   //�����ж� 
		{
			b[j]=a;
			j++;
		} 
	}
	t=b[0];
	b[0]=b[j/2];
	b[j/2]=t;
	for(i=0;i<j;i++)  //��ֹ˳����� 
	printf("%d ",b[i]);
	return 0;
}
