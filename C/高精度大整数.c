#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_LEN 2000
//仅限正整数相加 
int an1[MAX_LEN + 10];
int an2[MAX_LEN + 10];							// 定义两个整形数组 
char szLine1[MAX_LEN + 10];
char szLine2[MAX_LEN + 10];						//定义两个字符数组 
int main()
{
    scanf("%s",szLine1);
    scanf("%s",szLine2);						//以字符形式接收两个大整数 
    int i,j ;
    memset(an1, 0, sizeof(an1));
    memset(an2, 0, sizeof(an2));				//将整形数组的每一个元素赋值为0 
    int nLen1 = strlen(szLine1);
    				//用nlen1保存szLine1的长度 
    j=0 ;
    for(i = nLen1 - 1; i >= 0; i--) 
	{
		an1[j++] = szLine1[i] - '0';			//将字符数组1中的数字字符转化为数字首位交换存储在整形数组1中 
	} 
    int nLen2=strlen(szLine2);	
    				//用nlen2保存szLine2的长度
    j=0;										//重置j的值为0 
    for(i = nLen2 - 1; i >= 0; i--)
	{
		an2[j++]=szLine2[i] - '0';				//将字符数组2中的数字字符转化为数字存储在整形数组2中 
	} 

    for(i = 0;i < MAX_LEN; i++)					
    {
        an1[i] += an2[i];						//将两个数组对齐，每一位按加法竖式计算 
        if(an1[i] >= 10)						//如果两个数之和大于10 
        {
            an1[i] -= 10;						//那么只取个位部分储存到当数组位置 
            an1[i+1]++;							//并且让数组的下一个位置进位1 
        }
    }

    bool bStartOutput = false;					//定义一个布尔变量默认为false 
    for(i = MAX_LEN;i >= 0; i--)				//从数组尾部输出数字 
    {
        if(bStartOutput) printf("%d",an1[i]);	//如果布尔变量成立,输出元素an1[i],此处意义在于排除没被赋值的数组元素 
        else if(an1[i])							//如果a[i]成立 
        {	
            printf("%d",an1[i]);				//输入数组中的数字
            bStartOutput = true ;				//给布尔变量新值true 
        }
    }
    if(!bStartOutput) printf("0");				//输入结果为0的示例 
    return 0 ;
}
