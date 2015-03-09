#include<stdio.h>
int main()
{
	char string[80];
	int i,num=0,word=0;							//word表示一个字符是否处于一个单词中，默认没有 
	char c;
	gets(string);
	for(i = 0; (c=string[i]) != '\0'; i++)		//使用循环遍历字符串中所有字符 
	{ 
		if(c == ' ') word = 0;                  //如果一个单词还没开始则word赋值为0 
		else 									//如果c是字母，即一个新的单词已经开始 
		{ 
			if(word==0)                         //因为查找到当前字符是字母并且上一个字符是空格 
        	{
	 			word=1;							//那么将word的值置为1，表示这个单词还没结束 
	 			num++;							//单词的数量自加1 
	 		} 
		}
	} 
 	printf("一共输入了 %d 个单词\n",num);	
 	return 0;
}
