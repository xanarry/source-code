/************************
用于查找另外一句中缺失的单词
例：i love you
	i _ you
输入：love
************************/ 
#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	int i,j,l;
	int flag; 
	char str1[20];			
	char str2[20];							//定义两个字符串 
	scanf("%d",&n);
	getchar();								//吸收输入数字的回车 
	for(l = 0; l < n; l++)
	{
		gets(str1);
		gets(str2);
		for(j = 0; j < strlen(str2); j++)
		{
			if(str1[j] != str2[j])
			{
				flag = j;
				break;						//查找两个字符串的开始不同的下标 
			}
		}
		for(i = j; i < strlen(str1); i++)
		{
			if(str1[i] == ' ' || str1[i] == '\0')	//从之前记录下标处向后查找一个单词的结束 
			{
				str1[i] = '\0';				//在结束的位置放上'\0'终止字符串 
				break;						
			}
		}
		printf("%s",str1 + flag);			//输入单词 
	}
	return 0;
} 
