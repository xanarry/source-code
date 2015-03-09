#include<stdio.h>
#include<string.h>
int main()
{
	char a[10];
	int i;
	int n;
	scanf("%d",&n); 
	for(i = 0;i < n; i++)
	{
		scanf("%s",a);				//输入一个英语数字 
		if(strlen(a) == 5) 
			printf("3\n");			//如果字符串长度是5直接输出3 
		else if((a[0] == 'o') + (a[1] == 'n') + (a[2] == 'e') >= 2)
			printf("1\n");			//通过真假值运算，如果有两个字母是单词1
		else if((a[0] == 't') + (a[1] == 'w') + (a[2] == 'o') >= 2)
		    printf("2\n");			//通过真假值运算，如果有两个字母是单词2
	}
	return 0;
}
		
