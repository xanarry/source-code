'''
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
 '''
import math#引入数学函数库

#计算表达式的值，返回该值和表达式的后缀表达式
def calculate_expression(expression):
	'''
	 *遇到字符要先与栈顶的运算符做优先级比较，如果外面的运算
	 *符优先级高则入栈，否则栈顶运算符出栈并添加到后缀表达式中
	 *在出栈时有需要连续出栈的情况，所有使用一个while循环
	'''
	operators = []#操作符栈
	operators.append('e')#插入'e'标记当前是空栈
	operands = []#操作数栈
	operand_start = operand_end = 0#定义操作数的起终点下标标记
	postfix = ""

	for i in range(len(expression)):#遍历表达式
		if is_operator(expression, i):
			operand_end = i

			if operand_end > operand_start:#获取操作数
				new_num = float(expression[operand_start : operand_end])
				operands.append(new_num)#操作数入栈
				postfix += str(new_num) + " "#添加到后缀表达式
			
			#开始运算符优先级比较
			if is_higher_priority(operators[len(operators) - 1], expression[i]):#较大优先级的运算符入栈
				operators.append(expression[i])
			else:#否则开始运算
				while not is_higher_priority(operators[len(operators) - 1], expression[i]):#应对连续出栈计算的情况
					top_stack_optr = operators.pop()
					postfix += top_stack_optr + " "
					operand_a = operand_b = None
					
					operand_b = operands.pop()#无论如何出栈第一个数
					if top_stack_optr not in {'!', 's', 'c', 't', 'l', 'q'}:#如果是双目运算符出栈第二个数
						operand_a = operands.pop()
					operands.append(calculate(operand_a, operand_b, top_stack_optr))#调用函数计算结果并入栈

				if expression[i] != ')':
					operators.append(expression[i])

				if operators[len(operators) - 1] == '(':#栈顶遇到左括号直接出栈
					operators.pop()

			operand_start = operand_end + 1;

	postfix += operators.pop()#出栈等号
	operators.clear()#清空栈

	result = operands.pop()#保存结果
	operands.clear()#清空栈
	return result, postfix#返回计算结果和后缀表达式

def factorial(n):
	#循环计算阶乘
	result = i = 1
	while i <= n:
		result *= i
		i += 1
	return result

def calculate(a, b, operator):
	#单目运算符调函函数库和自定义函数
	if operator == '!':
		return factorial(b)
	elif operator == 's':
		return math.sin(b)
	elif operator == 'c':
		return math.cos(b)
	elif operator == 't':
		return math.tan(b)
	elif operator == 'l':
		return math.log(b) / math.log(10)
	elif operator == 'q':
		return math.sqrt(b)
	elif operator == '^':
		return a ** b
	elif operator == '+':
		return a + b
	elif operator == '-':
		return a - b
	elif operator == '*':
		return a * b
	elif operator == '/':
		return a / b
	
def is_operator(expression, index):#判断是否是运算符，主要处理符号的各种清空
	operators_set = {'+', '=', '*', '/', '^', '!', 's', 'c', 't', 'l', 'q', '(', ')'}
	numbers_set = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
	if expression[index] in operators_set:
		return True
	elif expression[index] not in numbers_set and expression[index] != '.':
			if index > 0 and (expression[index - 1] in numbers_set or expression[index - 1] == ')'):
				return True
	return False

def is_higher_priority(top_stack_optr, outer_optr):#定义运算符的优先级
	#False means out, True means in
	if top_stack_optr == 'e':
		return True

	if outer_optr == '+' or outer_optr == '-':
		if top_stack_optr == '^' or top_stack_optr == '*' or top_stack_optr == '/' or top_stack_optr == '+' or top_stack_optr == '-':
			return False
		elif top_stack_optr == '(':
			return True

	elif outer_optr == '*' or outer_optr == '/':
		if top_stack_optr == '+' or top_stack_optr == '-' or top_stack_optr == '(':
			return True
		elif top_stack_optr == '^' or top_stack_optr == '*' or top_stack_optr == '/':
			return False

	elif outer_optr == '^' or outer_optr == 's' or outer_optr == 'c' or outer_optr == 't' or outer_optr == 'l' or outer_optr == 'q' or outer_optr == '!' or outer_optr == '(':
		return True

	elif outer_optr == ')':
		if top_stack_optr != '(':
			return False
		else:
			return True

	elif outer_optr == '=':
		if top_stack_optr != 'e':
			return False
		else:
			return True

#测试数据
expressions = [
	"3+2*(5+3*5)+2=",# 45     0
	"3*-5/3/-5=", #1          1
	"6*(5-2)/-2=", #-9        2
	"7+3--5=", #15            3
	"-3*2+5*-3+(7*(8-2))+5=", #26   4 
	"4.5+4.5+1-0.25=", #9.75        5
	"1.2+2.1*-2.1=", #-3.21         6
	"1+2+3+4=", #10                 7
	"3+2*(5+5+5+3*5)+2=", #65       8
	"1+2*3+(4*5+6)*7=", #189        9
	"(1+2)*3*4=", #36               10
	"1*2*3*4*5*6=", #720            11
	"(2+3)^2=", #25                 12
	"3+5^2*2=", #53                 13
	"(2+1*2+1)^(2*1+1)*3+2*2=", #379     14
	"3+3*(1+3)*q(99+1)=", #123,%表示根号 15
	"3+ql100*2=", #7.29                  16
	"10+q((20+5)*4)*7+2*q100=", #100     17
	"5*(q100^2)=", #500                  18
	"5+(q100+3+7)+5=", #20               19
	"q100+q100*q100+5=", #115            20
	"1111111111111111+1111111111111111=", #222222222     21
	"l100+q100=", #14.605                                22
	"3+(l100+q100)*s3.14+7=", #10.023260966892500404     23
	"!6+!6=", #2x3x4x5x6=720x2=1440                      24
	"q100+!6+!4*2+(1+2*4.5)=", #10+720+48+10=788         25
	]

#expression  = input("input a expression:")
index = 24
#expression = expressions[index]
#print(expression + str(calculate_expression(expression)))

for expression in expressions:
	result, postfix = calculate_expression(expression)
	print(expression + str(result), "\t\t\tpostfix", postfix)

