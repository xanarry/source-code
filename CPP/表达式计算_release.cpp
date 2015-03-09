#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cctype>
#include <stack>

//宏定义，用于辅助栈中运算符的比较操作
#define EMPTY 'E'
#define IN true
#define OUT false

using namespace std;

double calculate_expression(string expression);//转换为后缀表达式
bool is_operator(string expression, int index);//判读符号是否为运算符
bool is_higher_priority(char top_stack_optr, char outter_optr);//符号优先级比较


int main(int argc, char const *argv[])
{
	string expression;

	//测试数据
	string a = "3+2*(5+3*5)+2=";//45 true
	string b = "3*-5/3/-5=";//1 true
	string c = "6*(5-2)/-2=";//-9 true
	string d = "7+3--5=";//15 true
	string e = "-3*2+5*-3+(7*(8-2))+5=";//26 true
	string f = "4.5+4.5+1-0.25=";//9.75 true
	string g = "1.2+2.1*-2.1=";//-3.21 true
	string h = "1+2+3+4=";//10 true
	string i = "3+2*(5+5+5+3*5)+2=";//65
	string j = "1+2*3+(4*5+6)*7=";//189 true
	string k = "(1+2)*3*4=";//36 true
	string l = "1*2*3*4*5*6=";//720 true
	string m = "(2+3)^2=";//25 true
	string n = "3+5^2*2=";//53 true
	string o = "(2+1*2+1)^(2*1+1)*3+2*2=";//379 true
	expression = e;

	//	cin >> expression;
	cout << expression << calculate_expression(expression) << endl;
	return 0;
}

double calculate_expression(string expression)
{
	//定义运算符栈
	stack<char> operators;
	operators.push(EMPTY);

	//定义操作数栈
	stack<double> operands;

	//保存栈顶符号
	char top_stack_optr;
	//数字在字符串中的起点,初始化为0
	int operand_start = 0;
	//数字在字符串中的终点,初始化为0
	int operand_end = 0;

	//定义前后两个操作数
	double operand_a;
	double operand_b;

	for (int i = 0; i < expression.length(); i++)//遍历输入的中缀表达式
	{
		if (is_operator(expression, i))//如果遇到运算符
		{
			/*遇到数字直接添加到表达式中*/
			operand_end = i;//设置数字的终点下标
			if (operand_end > operand_start)//如果不是空串
			{
				//将字符串转换为浮点数
				double new_operand = atof(expression.substr(operand_start, operand_end - operand_start).c_str());
				//操作数入栈
				operands.push(new_operand);
			}

			/*遇到字符要先与栈顶的运算符做优先级比较，如果外面的运算
			 *符优先级高则入栈，否则栈顶运算符出栈并添加到后缀表达式中
			 *在出栈时有需要连续出栈的情况，所有使用一个while循环
			 */

			//如果栈外运算符优先级高，直接入栈
			if (is_higher_priority(operators.top(), expression[i]) == IN)
				operators.push(expression[i]);
			//栈外运算符优先级低，则栈中运算符出栈添加到后缀表达式中
			else
			{
				while (is_higher_priority(operators.top(), expression[i]) == OUT)
				{
					//获取栈顶符号并删除
					top_stack_optr = operators.top();
					operators.pop();//删除

					//取出操作数栈的数b
					operand_b = operands.top();
					operands.pop();

					//取出操作数栈的数a
					operand_a = operands.top();
					operands.pop();

					//计算两个操作数的结果并推入操作数栈
					switch (top_stack_optr)
					{	
						case '+':
							operands.push(operand_a + operand_b);
							break;
						case '-':
							operands.push(operand_a - operand_b);
							break;
						case '*':
							operands.push(operand_a * operand_b);
							break;
						case '/':
							operands.push(operand_a / operand_b);
							break;
						case '^':
							operands.push( pow(operand_a,operand_b) );
							break;
					}
				}

				//')'不用入栈
				if (expression[i] != ')')
					operators.push(expression[i]);

				//出栈过程结束后检查栈顶是否是'(',是的话应将其出栈
				if (operators.top() == '(')
					operators.pop();
			}
			//后移操作数的起点下标
			operand_start = operand_end + 1;
		}
	}

	//删除=
	operators.pop();
	//删除默认的'E'
	operators.pop();
	
	//保存运算结果并清空栈
	double result = operands.top();
	operands.pop();

	//返回运算结果
	return result;
}

bool is_operator(string expression, int index)
{
	if (expression[index] == '(' || expression[index] == ')')//()肯定是运算符
		return true;

	if ( !isdigit(expression[index]) && expression[index] != '.')//如果当前字符不是数字，并且不是'.'
		if (index - 1 >= 0 && (isdigit(expression[index - 1]) || expression[index - 1] == ')' ))//但是该字符前面是一个数字或者是")"，那么肯定是运算符
			return true;

	return false;
}

bool is_higher_priority(char top_stack_optr, char outter_optr)
{
	/*
	 *符号优先级的比较
	 *其中 加减 < 乘除 < 左括号
	 *但符号栈为空时，任何符号都入栈
	 *遇到 等号 无论如何符号开始出栈
	 */
	if (top_stack_optr == EMPTY)
		return IN;

	switch (outter_optr)
	{
		//case represent outter operator
		case '+':
		case '-':
			if (top_stack_optr == '^' || top_stack_optr == '*' || top_stack_optr == '/' || top_stack_optr == '+' || top_stack_optr == '-')
				return OUT;
			if (top_stack_optr == '(')
				return IN;

		case '*':
		case '/':
			if (top_stack_optr == '+' || top_stack_optr == '-' || top_stack_optr == '(')
				return IN;
			else if (top_stack_optr == '^' || top_stack_optr == '/' || top_stack_optr == '*')
				return OUT;

		case '^':
			if (top_stack_optr == '*' || top_stack_optr == '/' || top_stack_optr == '+' || top_stack_optr == '-')
				return IN;
			else
				return OUT;

		case '(':
			return IN;

		case ')':
			if (top_stack_optr != '(')
				return OUT;
			else 
				return IN;

		case '=':
			if (top_stack_optr != EMPTY)
				return OUT;
			else
				return IN;
	}
}