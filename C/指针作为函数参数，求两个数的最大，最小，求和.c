#include<stdio.h>
int main()
{
	int max(int,int);
	int min(int,int);
	int add(int,int);
	int process(int,int,int (*fun)(int,int));//�ú������������� 
	int a,b;
	printf("input a and b:\n");
	scanf("%d%d",&a,&b);
	printf("max=%d\n",process(a,b,max));//��������Ԫ�غͺ���ʵ�ּ��� 
	printf("min=%d\n",process(a,b,min));
	printf("add=%d\n",process(a,b,add));
	return 0;
}
max(int x,int y)
{
	return x>y?x:y;
}
min(int x,int y)
{
	return x<y?x:y;
}
add(int x,int y)
{
	return x+y;
}
process(int x,int y,int (*fun)(int,int))
{
	return (*fun)(x,y);
}

