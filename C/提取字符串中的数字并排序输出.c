#include <stdio.h>
#include <string.h>
int main()
{
	char a[20];
	int b[20];
	int i,j,k,t;
	gets(a);								//获取字符串 
	for(i = 0, j = 0; i < strlen(a); i++)
	{
		if(a[i] >= 48 && a[i] <= 57)
		{
			b[j] = a[i]-48;					//提取字符串中的数字，存储到新的数组 
			j++;
		}
	}
	for(k = 0; k < j-1; k++)
	{
		for(i = 0; i < j-1-k; i++)
		{
			if(b[i] > b[i+1])
			{
				t = b[i];
				b[i] = b[i+1];
				b[i+1] = t;
			}
		}
	}										//对数组排序 
	for(i = 0; i < j; i++)
	{
		printf("%d ",b[i]);
	}										//输出数组 
	return 0;
}
