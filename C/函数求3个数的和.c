#include<stdio.h>
int sum(int a, int b, int c)
{
	int n;
  	n = a + b + c;
  	return n;
}								//���庯������������֮�Ͳ����� 
int main()
{
  	int x,y,z;
  	printf("����3����:");
  	scanf("%d%d%d",&x,&y,&z);
  	printf("%d\n",sum(x,y,z));
  	return 0;
}

