#include<stdio.h>
int h()
{
	int i,s = 0;
	for(i = 0; i <= 100; i++)
	s += i;
	return s;					//����0-100��ֵ 
}
int h1()
{
	int a,s1 = 0;
	for(a = 0; a <= 1000; a++)
	s1 += a;
	return s1;					//����0-1000��ֵ 
}
int h2()
{
	int b,s2=0;
	for(b = 0;b <= 234;b ++)
	s2 += b;
	return s2;					//����0-234��ֵ
}
int main()
{
	printf("%d\n",h());
	printf("%d\n",h1());
	printf("%d",h2());			//�ֱ�������������ķ���ֵ 
	return 0;
}
