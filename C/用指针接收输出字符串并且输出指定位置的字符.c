#include<stdio.h>
int main()
{
	char *p;
	int i;
	p="abcdefghijklmnopqr";
	printf("%s\n",p);
	printf("input a location:");
	scanf("%d",&i);
	printf("the %dth character is %c\n",i,*(p+i-1));//ʹ��ָ��ָ��Ԫ�� 
	printf("after %c is:\n%s",*(p+i-1),p+i);
	return 0;
}
