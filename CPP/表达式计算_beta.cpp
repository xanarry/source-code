/*
 *name: 复合表达式求值
 *data: 2015-2-16
 *author: xanarry
 *note: 主要使用栈的特点，将正常输入的中缀表达式转化为后缀表达式
 *      在转化的过程中实现表达式值的计算，整数小数皆可，并增添加
 *		了三角函数，log，sqrt，以及阶乘的实现，其中sin则在表达式
 *      中输入s,例如sin(60)，应输入s60，单个运算数不用添加括号即
 *		"s(60)="，其他函数同样如此，阶乘的输入应将！写在数字之前，
 * 		比如要计算6的阶乘，正确的输入是“!6=”，其他的情况则正常输即可。
 *      
 *      如需新增一些计算功能，主要针对单目运算的函数，可自定义函数
 *      请依次修改一下地方：
 *          1：宏定义，请在代码最前面添加，示例如代码
 *			2：如果新增的计算时单目运算，请在calculate_expression中判断是否是单目运算符的地方将其添加
 *			3：在calculate_expression中的switch语句中定义其运算方法
 *			4：在is_operator函数中添加该运算符
 *			5：在is_higher_priority中新增该运算符的优先级
 *      
 */

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

//定义三角函数以及科学运算函数
#define SIN 's'
#define COS 'c'
#define TAN 't'
#define SQRT 'q'
#define LOG 'l'
#define FAC '!'//阶乘

using namespace std;

double calculate_expression(string expression);//计算表达式
double factorial(double n);//计算阶乘
bool is_operator(string expression, int index);//判读符号是否为运算符
bool is_higher_priority(char top_stack_optr, char outer_optr);//符号优先级比较

int main(int argc, char const *argv[])
{
	//测试数据
	string expressions[] = {
	/*0*/	"3+2*(5+3*5)+2=",//45 true
	/*1*/	"3*-5/3/-5=",//1 true
	/*2*/	"6*(5-2)/-2=",//-9 true
	/*3*/	"7+3--5=",//15 true
	/*4*/	"-3*2+5*-3+(7*(8-2))+5=",//26 true
	/*5*/	"4.5+4.5+1-0.25=",//9.75 true
	/*6*/	"1.2+2.1*-2.1=",//-3.21 true
	/*7*/	"1+2+3+4=",//10 true
	/*8*/	"3+2*(5+5+5+3*5)+2=",//65
	/*9*/	"1+2*3+(4*5+6)*7=",//189 true
	/*10*/	"(1+2)*3*4=",//36 true
	/*11*/	"1*2*3*4*5*6=",//720 true
	/*12*/	"(2+3)^2=",//25 true
	/*13*/	"3+5^2*2=",//53 true
	/*14*/	"(2+1*2+1)^(2*1+1)*3+2*2=",//379 true
	/*15*/	"3+3*(1+3)*q(99+1)=",//123,%表示根号
	/*16*/	"3+ql100*2=",//7.29
	/*17*/	"10+q((20+5)*4)*7+2*q100=",//100 true
	/*18*/	"5*(q100^2)=",//500 true
	/*19*/	"5+(q100+3+7)+5=",//20
	/*20*/	"q100+q100*q100+5=",//115
	/*21*/	"1111111111111111+1111111111111111=",//2222222222222222
	/*22*/	"l100+q100=",//14.605
	/*23*/	"3+(l100+q100)*s3.14+7=",//10.023260966892500404
	/*24*/  "!6+!6=",//2x3x4x5x6=720x2=1440
	/*25*/  "q100+!6+!4*2+(1+2*4.5)=",//10+720+48+10=788
	/*26*/  "l100=",//2
	/*27*/  "l100+l(50+50)=",//2+2=4
	};
	
	string expression;
	//	cin >> expression;

	int i = 26;
	const int ex_count = 27;
	for (; i <= ex_count; i++)
		cout << expressions[i] << calculate_expression(expressions[i]) << endl;
	return 0;
}

double calculate_expression(string expression)
{
	/*
	 *遇到字符要先与栈顶的运算符做优先级比较，如果外面的运算
	 *符优先级高则入栈，否则栈顶运算符出栈并添加到后缀表达式中
	 *在出栈时有需要连续出栈的情况，所有使用一个while循环
	 */

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

	//字符串流，构造后缀表达式
	stringstream ss;

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
				//cout << "push " << new_operand << " into operands stack" << endl;
				ss << new_operand << " ";
			}

			//如果栈外运算符优先级高，直接入栈
			if (is_higher_priority(operators.top(), expression[i]) == IN)
			{
				operators.push(expression[i]);
				//cout << "push " << expression[i] << " into operators stack" << endl;
			}
			//栈外运算符优先级低，则栈中运算符出栈添加到后缀表达式中
			else
			{
				while (is_higher_priority(operators.top(), expression[i]) == OUT)
				{
					//获取栈顶符号并删除
					top_stack_optr = operators.top();
					operators.pop();//删除
					//cout << "pop " << top_stack_optr << " from operators stack" << endl;
					ss << top_stack_optr << " ";

					//定义前后两个操作数
					double operand_a;
					double operand_b;

					//取出操作数栈的数b
					operand_b = operands.top();
					operands.pop();

					//如果是单目运算符，只取一个数，否则取两个
					if (top_stack_optr != SIN
						&& top_stack_optr != COS 
						&& top_stack_optr != TAN 
						&& top_stack_optr != LOG 
						&& top_stack_optr != SQRT 
						&& top_stack_optr != FAC )
					{
						//取出操作数栈的数a
						operand_a = operands.top();
						operands.pop();
					}
					
					//计算两个操作数的结果并推入操作数栈
					switch (top_stack_optr)
					{	
						case '+':
							operands.push(operand_a + operand_b);
							//cout << "cal & push " << operand_a << "+" << operand_b << "=" << operand_a + operand_b << endl;
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
						case SIN:
							operands.push(sin(operand_b));
							//cout << "cal & push sin(" << operand_b << ")=" << sin(operand_b) << endl;
							break;
						case COS:
							operands.push(cos(operand_b));
							break;
						case TAN:
							operands.push(tan(operand_b));
							break;
						case LOG:
							operands.push(log(operand_b) / log(10));
							break;
						case SQRT:
							operands.push(sqrt(operand_b));
							break;
						case FAC:
							operands.push(factorial(operand_b));
							break;
					}
				}

				//')'不用入栈
				if (expression[i] != ')')
				{
					operators.push(expression[i]);
					//cout << "push " << expression[i] << " into operators stack" << endl;
				}

				//出栈过程结束后检查栈顶是否是'(',是的话应将其出栈
				if (operators.top() == '(')
					operators.pop();
			}
			//后移操作数的起点下标
			operand_start = operand_end + 1;
		}
	}

	//插入=号到表达式
	ss << operators.top();
	//删除=
	operators.pop();
	//删除默认的'E'
	operators.pop();
	
	//保存运算结果并清空栈
	double result = operands.top();
	operands.pop();

//	cout << ss.str() << endl;
	//返回运算结果
	return result;
}

bool is_operator(string expression, int index)
{
	if (expression[index] == '=' 
		|| expression[index] == '(' 
		|| expression[index] == ')' 
		|| expression[index] == SIN 
		|| expression[index] == COS 
		|| expression[index] == TAN 
		|| expression[index] == SQRT 
		|| expression[index] == LOG 
		|| expression[index] == FAC)//这些肯定是运算符
		return true;

	if ( !isdigit(expression[index]) && expression[index] != '.')//如果当前字符不是数字，并且不是'.'
		if (index - 1 >= 0 && (isdigit(expression[index - 1]) || expression[index - 1] == ')' ))//但是该字符前面是一个数字或者是")"，那么肯定是运算符
			return true;

	return false;
}

double factorial(double n)
{
	double result = 1;
	int i = 1; 
	while (i <= n)
		result *= i++;
	return result;
}

bool is_higher_priority(char top_stack_optr, char outer_optr)
{
	/*
	 *符号优先级的比较
	 *其中 加减 < 乘除 < 左括号
	 *但符号栈为空时，任何符号都入栈
	 *遇到 等号 无论如何符号开始出栈
	 */
	if (top_stack_optr == EMPTY)
		return IN;

	switch (outer_optr)
	{
		//case represent outter operator
		case '+':
		case '-':
			if (top_stack_optr == '^' 
				|| top_stack_optr == '*' 
				|| top_stack_optr == '/' 
				|| top_stack_optr == '+' 
				|| top_stack_optr == '-')
				return OUT;

			if (top_stack_optr == '(')
				return IN;

		case '*':
		case '/':
			if (top_stack_optr == '+' || top_stack_optr == '-' || top_stack_optr == '(')
				return IN;
			else if (top_stack_optr == '^' || top_stack_optr == '/' || top_stack_optr == '*')
				return OUT;

		case '^'://之所以要有top_satck_opre == '(',是因为存在单目运算符，比如表达式："5*(%100^2)="就去掉等于'('就会运行出错
			if (top_stack_optr == '*' 
				|| top_stack_optr == '/' 
				|| top_stack_optr == '+' 
				|| top_stack_optr == '-' 
				|| top_stack_optr == '(')
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

		case SIN:
		case COS:
		case TAN:
		case LOG:
		case SQRT:
			return IN;

		case '=':
			if (top_stack_optr != EMPTY)
				return OUT;
			else
				return IN;
	}
}
