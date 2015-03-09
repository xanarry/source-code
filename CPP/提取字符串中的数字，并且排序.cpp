#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a>b;
}											//创建sort函数的比较调用函数 

int main()
{
	int a[250];
	char b[20];
	int i,j;
	gets(b);								//接受字符串 
	for(i = 0, j = 0; i < strlen(b); i++)
	{
		if(b[i]>='0' && b[i]<='9')
		{
			a[j++] = b[i]-'0';				//提取数字 
		}
	}
	
	sort(a,a+j,cmp);						//调用函数sort排序 
	
	for(int i = 0; i < j; i++)
	{
		printf("%4d",a[i]);
	}										//输出数组 
	return 0; 
}
