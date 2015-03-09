#include <stdio.h>
#include <string.h>

int main()
{
	char a[100];
	int pos;
	int len;
	int l;
	int i;
	printf("请输入原字符串:\n");
	gets(a);
	puts("这是您输入的的原字符串：");
	puts(a);
	l = strlen(a);
	printf("请输入删除的位置及长度:");
	scanf("%d %d",&pos,&len);
	for(i = pos-1; i < l; i++)
	{
		a[i] = a[i + len];//将起始位置之后的每个字符向前移动len个位置 
	}
	a[l - len] = '\0';//减短字符串len长度 
	puts(a); 
	return 0;
}
