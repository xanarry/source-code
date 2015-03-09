#include <iostream>
#include <cstring>
#include <stack>
using namespace std;


template <class T>
void StackClear(stack<T> &s)			//清空栈
{
    while(!s.empty())
        s.pop();
}


/*
判断读取到的字符是否是运算符
*/
int IsOperator(char c)
{
    switch(c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '=':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}


/*
比较前后两个运算符的优先级
(为了判断方便，增设一个等号“=”作为表达式的定界符)
top_optr>=current_optr返回1
top_optr<current_optr返回-1
top_optr、current_optr分别为左右括号返回0
*/
int Priority(char top_optr, char current_optr)
{
    int pri;
    switch(current_optr)
    {
    case '+':
    case '-':
        if(top_optr == '(' || top_optr == '=')
            pri = -1;
        else
            pri = 1;
        break;

    case '*':
    case '/':
        if(top_optr == '*' || top_optr == '/' || top_optr == ')')
            pri = 1;
        else
            pri = -1;
        break;

    case '(':
        if(top_optr == ')')		//左括号右侧不能马上出现右括号
        {
            cout << "表达式格式有误！\n";
            return 0;
        }
        else
            pri = -1;
        break;

    case ')':
        if(top_optr == '(')
            pri = 0;		 //左右括号配对
        else
            pri = 1;
        break;

    case '=':
        if(top_optr == '(')
        {
            cout << "括号不匹配\n";
            return 0;
        }
        else if(top_optr == '=')
            pri = 0;		//等号配对，返回0
        else
            pri = 1;
        break;
    }
    return pri;
}


/*
根据运算符和两个操作数进行运算
*/
double calculate(double a, int oper, double b)
{
    switch(oper)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b != 0)
            return a / b;
        else
        {
            cout << "被0除错误\n";
            return 0;
        }
    }
}


/*
对多位数进行数值拼接
*/
double NumberSplicing(char ch[])
{
    int dot = 0; 	//是否遇到小数点的标志
    double temp = 0;	//临时拼接的数值
    static int len = 10;

    for(int n = 0; n < strlen(ch); n++)
    {
        char c = ch[n];
        if(c == '.')
            dot = 1;	//将标志设为1
        else
        {
            c -= '0';		//先将相应的数字字符转换成整数
            if(dot == 0)
                temp = temp * 10 + c;
            else
            {
                temp = temp + (double)c / len; //小数点第一位的数x相当于 top_optr/10;
                len *= 10;					  //小数点的第二位数相当于 x/100;
                //cout<<"数字转换中的暂存值："<<temp<<endl;
            }
        }
    }
    return temp;
}


/*
计算表达式的值：
初始化两个栈：一个操作数栈，一个运算符栈。

从左至右遍历每一个字符，遍历过程中遵循步骤和原则如下：
（1）遇到数字则直接压到数字栈顶。
（2）遇到运算符（+-* /）时，若操作符栈为空，则直接放到操作符栈顶，否则，见（3）。
（3）若操作符栈顶元素的优先级比当前运算符的优先级小，则直接压入栈顶，否则执行步骤（4）。
（4）弹出数字栈顶的两个数字并弹出操作符栈顶的运算符进行运算，把运算结果压入数字栈顶，重复（2）和（3）
	 直到当前运算符被压入操作符栈顶。
（5）遇到左括号“（”时则直接压入操作符栈顶。
（6）遇到右括号“）”时则依次弹出操作符栈顶的运算符运算数字栈的最顶上两个数字，直到弹出的操作符为左括号。
*/
double CalcExp(char express[])
{
    double a, b;				//两个操作数
    char opera;				//运算符
    char c;					//字符变量
    char top_optr;					//x用来获取运算符栈栈顶的运算符
    stack<char> oper;
    stack<double> data;	//运算符栈栈顶的运算符，操作数栈
    char tempNum[20];		//与多位数对应的字符数组
    int j = 0;

    int i = 0, flag = 0;		//flag做标志，用来处理多位数

    oper.push('=');			//先将定界符(=)推入操作符栈

    c = express[i++];
    double num = 0;

    while(c != '=' || top_optr != '=')			//循环处理表达式中的每个字符
    {
        if(IsOperator(c))	//若是运算符
        {
            if(flag)		//将操作数入栈（因为读取到数字时，数字并没有及时进入数字栈）
            {
                tempNum[j] = 0;
                j = 0;
                num = NumberSplicing(tempNum);	//遇到操作符时，将数值拼接的结果返回回来
                //cout << "n----" << num << endl;
                data.push(num);			///////////////////////////////////////////////////////////
                num = 0; 				//入栈之后清空某一个操作数的暂存值
                flag = 0;				//且将标志置0，表示操作数已入栈
            }

            switch(Priority(top_optr, c))
            {
            case -1:	//当前运算符c大于前一运算符x
                //cout << "o----" << c << endl;
                oper.push(c);		//当前运算符进栈/////////////////////////////////
                c = express[i++];		//取表达式下一字符
                break;

            case 0:					//括号（等号）配对
                oper.pop();			//运算符左半部分出栈（抛弃）
                c = express[i++];		//取表达式下一字符
                break;

            case 1:						//当前运算符c小于等于前一运算符x
                opera = oper.top();		//出栈之前取得栈顶元素
                oper.pop();				//运算符出栈

                b = data.top();
                data.pop();
                a = data.top();
                data.pop();				//两个操作数出栈
                double t = calculate(a, opera, b);	//计算结果
                data.push(t);		//将结算结果入栈
                break;
            }
        }

        else if(c >= '0' && c <= '9' || c == '.')	//若输入的是数字字符(不入栈，因为可能是多位数字）
        {
            tempNum[j++] = c;
            flag = 1; 				//设置操作数。表示操作数未入栈
            c = express[i++];
        }
        else
        {
            cout << "输入有误\n";
            return 0;
        }

        top_optr = oper.top();		//获取运算符栈顶的元素
        //cout<<"栈顶的操作符为："<<top_optr<<endl;
    }

    num = data.top();

    StackClear(oper);
    StackClear(data);		//清空两个栈
    //cout<<num<<endl;

    return 	num;	//返回数字栈栈顶元素，即为计算结果

}


int main()
{
    char express[100] = "3*2+5*3+(7*(8-2))+5=";
    string a = "3+2*(5+3*5)+2=";//45 true
    string b = "3*-5/3/-5=";//
    string c = "6*(5-2)/-2=";//-9 ture
    string d = "7+3--5=";
    string e = "-3*2+5*-3+(7*(8-2))+5=";
    string f = "4.5+4.5+1-0.25=";
    string g = "1.233+2.1*-3.32=";
    string h = "1+2+3+4=";
    string i = "3+2*(5+5+5+3*5)+2=";//65
    //	cout<"请输入要计算的表达式（以=结束）:";
    //	cin>>express;
    cout << express << CalcExp(express);
    return 0;
}
