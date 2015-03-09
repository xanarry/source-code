/************************
用于查找另外一句中缺失的单词
例：i love you
	i _ you
输入：love
************************/ 
#include<stdio.h>
#include<string.h>
struct input
{
	char o[2000];
	char m[2000];
};												//因为一次输入两句，所以定义结构体 
int main(void)
{
	int t,i,flag,j,k;
	char temp[204][30];							//设定最大长度 
	scanf("%d",&t);								//记录有多少组数据 
	getchar();									//吸收输入语句中的换行 
	struct input sts[100];
	for(i = 0; i < t; i++)
    {
    	gets(sts[i].o);
    	gets(sts[i].m);							//接收一组数据 
    }
	for(j = 0; j < t; j++)
	{
		for(i = 0; i < strlen(sts[j].m); i++)
        {
    	    if(sts[j].o[i] != sts[j].m[i])
    	    {
    		   flag = i;						//查找并记录两个字符串中的不同位置 
    		   break;
       	    }
       }
       for(i = flag;(sts[j].o[i] != ' ' && sts[j].o[i] != '\0'); i++) //查找到一个单词的结束位置 
   	   {
           printf("%c",sts[j].o[i]);			//在完整字符串中记录的位置输出一个单词 
       }
        if(j < t-1) printf("\n");
   }
}
    		
