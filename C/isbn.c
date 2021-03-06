/*******************************************************************

描述Descript.

每一本正式出版的图书都有一个ISBN号码与之对应，ISBN码包括9位数字、1位
识别码和3位分隔符，其规定格式如“x-xxx-xxxxx-x”，其中符号“-”就是分
隔符（键盘上的减号），最后一位是识别码，例如0-670-82162-4就是一个标准
的ISBN码。ISBN码的首位数字表示书籍的出版语言，例如0代表英语；第一个分
隔符“-”之后的三位数字代表出版社，例如670代表维京出版社；第二个分隔符
后的五位数字代表该书在该出版社的编号；最后一位为识别码。
识别码的计算方法如下：
首位数字乘以1加上次位数字乘以2……以此类推，用所得的结果mod 11，所得的
余数即为识别码，如果余数为10，则识别码为大写字母X。例如ISBN号码
0-670-82162-4中的识别码4是这样得到的：对067082162这9个数字，从左至右，
分别乘以1，2，...,9,再求和，即0×1+6×2+……+2×9=158，然后取158 mod 11
的结果4作为识别码。
你的任务是编写程序判断输入的ISBN号码中识别码是否正确，如果正确，则仅输
出“Right”；如果错误，则输出你认为是正确的ISBN号码。

输入Input
输入只有一行，是一个字符序列，表示一本书的ISBN号码（保证输入符合ISBN号码
的格式要求）。
输出Output
输出共一行，假如输入的ISBN号码的识别码正确，那么输出“Right”，否则，按
照规定的格式，输出正确的ISBN号码（包括分隔符“-”）。
样例Sample
输入数据

【样例1】
0-670-82162-4
【样例2】
0-670-82162-0

输出数据

【样例1】
Right
【样例2】
0-670-82162-4

********************************************************************/ 
#include <stdio.h>
#include <string.h>
int main()
{
    int i,sum=0,j;
    char isbn[13];									//定义字符串最大长度13 
    gets(isbn);
    for(i = 0, j = 1; i < 12; i++)					//从前12个字符抽数字技术 
    {
        if(isbn[i] != '-')
        { 
            sum += ((isbn[i] - 48)*j);				//求和 
            j++;									
        }
    }
    if(sum%11==10 && isbn[12]=='X')	printf("Right");
    else if(sum%11+48 == isbn[12]) printf("Right");	//如果号码正确 
    else 
    {
    	if(sum%11 == 10) isbn[12]='X';
       	else isbn[12] = (sum%11 + 48);				//不正确的话，输出正确的号码 
       	printf("%s",isbn);   
    }
    return 0;
}
