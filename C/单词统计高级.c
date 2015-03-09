#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],c;
	int w=0,num=0;
	int i;
	gets(a);
	for(i = 0; (c=a[i]) != '\0'; i++)
	{
		if(c == ' ') w = 0;		//w记录当前字符是否正在一个单词中 
		else if(w == 0)
		{
			w = 1;
			num++;
		}
	}
	printf("%d",num);
	return 0;
}
