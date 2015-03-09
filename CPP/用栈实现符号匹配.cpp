/*
	date: 2014/6/5
	time: 20:07
	运行环境：windows 7 + MinGW + Sublime_text_3
	注意：此代码不能判断符号相互交叉的匹配，比如({)},只能测试{([])({})}类型的
*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Stack
{
	int size;//stack's max size
	char *base;
	char *top;
};

bool init_stack(Stack &s)//初始化栈
{
	char *tmp = new char[100];
	if (tmp == NULL)
	{
		cout << "applay for memory failed" << endl;
		exit(1);
	}
	s.base = s.top = tmp;
	s.size = 100;//最大栈容量
	return true;
}

bool push(Stack &s, char ch)//插入元素
{
	if (s.top - s.base > s.size - 1)//检查是否溢出
	{
		cout << "ERROR! STACKOVERFLLOW" << endl;
		return false;
	}
	*s.top = ch;//插入入元素
	s.top++;//栈顶指针上移
	return true;
}

bool pop(Stack &s)//删除元素
{
	if (s.base == s.top)
	{
		return false;
	}
	s.top--;//顶端指针下移
}

char get_top(Stack &s)//获取栈顶元素
{
	if (s.base == s.top)
	{
		return false;
	}
	char *tmp = s.top;//使用tmp表示临时指针，防止栈顶指针被修改
	tmp--;
	return *tmp;
}

bool empty(Stack &s)//判断是否为空栈
{
	if (s.base == s.top)
		return true;
	else
		return false;
}

//遍历全栈的函数，测试时用，能正常使用时可以不用
void traversal(Stack &s)
{
	if (s.base == s.top)
	{
		cout << "empty" << endl;
		return;
	}

	char *tmp = s.top;
	tmp--;

	while (tmp >= s.base)
	{
		cout << *tmp << "";
		tmp--;
	}
	cout << endl;
}
////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
	Stack s;
	init_stack(s);
	char str[100];
	cout << "input a charactor string \"() {} []\"" << endl;
	cin >> str;
	for (int i = 0; i < strlen(str); ++i)
	{
		switch(str[i])
		{
			//如果是左括号都将其入栈
			case '(': 
				push(s, '('); 
				break;
			case '[': 
				push(s, '[');
				break;
			case '{': 
				push(s, '{');
				break;
			//如果是右括号，
			case ')': 
				if (empty(s) || get_top(s) == ')')//判断当前栈是否为空，或者栈顶已经是右括号
					push(s, ')');//继续入栈
				else if (get_top(s) == '(') //如果正好前后匹配，则清除栈顶元素
					pop(s);
				break;
			case ']':
				if (empty(s) || get_top(s) == ']')
					push(s, ']');
				else if (get_top(s) == '[')
					pop(s);
				break;
			case '}':
				if (empty(s) || get_top(s) == '}')
					push(s, '}');
				else if (get_top(s) == '{')
					pop(s);
				break;
			default:
				cout << "what you've input is invalid" << endl;
				return 1;
		}
	}

	if (s.base == s.top)
		cout << "congratuate, all charactor has matched" << endl;
	else
		cout << "sorry! \'" << *s.base << "\' can not matched" << endl;//只能输出栈底没有匹配的符号
	return 0;
}
/*
((({{[[[(({[]}))]]]}})))
*/
