/*
	题目地址：https://www.smartoj.com/p/1020
	代码时间：2014/5/25 16:29
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void conduct(string a, int p1, int p2, int p3);
void function3(string a, int p2, int p3);
void function2(string a, int p2, int p3);
void function1(string a, int p2, int p3);

int main(int argc, char const *argv[])
{
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string a;
	cin >> a;
	conduct(a, p1, p2, p3);
	return 0;
}

void conduct(string a, int p1, int p2, int p3)
{
	if (p1 == 1)//fill '-' with lower litter
		function1(a, p2, p3);

	if (p1 == 2 )//fill '-' with upper litter
		function2(a, p2, p3);

	if (p1 == 3)//fill '-' with '*'
		function3(a, p2, p3);
}


void function1(string a, int p2, int p3)
{
	cout << a[0];
	for (int i = 1; i < a.size(); ++i)
	{
		if (a[i] != '-')	
			cout << a[i];//排除所有“-”
		else
		{
			if ( ((a[i+1] - a[i-1]) > 1) && ((isalpha(a[i+1]) && isalpha(a[i-1])) || (isdigit(a[i+1]) && isdigit(a[i-1]) )))//如果前后递增且差值大于1
			{
				if (p3 == 1)//升序
				{
					for (char j = a[i-1]+1; j < a[i+1]; ++j)//遍历每个要输出的字母
					{
						for (int k = 0; k < p2; ++k)//指定每个字母的输出次数
						{
							cout << j;
						}
					}
				}

				if (p3 == 2)//降序
				{
					for (char j = a[i+1]-1; j > a[i-1]; --j)//同上
					{
						for (int k = 0; k < p2; ++k)//同上
						{
							cout << j;
						}
					}
				}
			}
			else if(a[i+1] - a[i-1] != 1)
				cout << '-';//如果“-”两边的字母是连续的，则输出“-”还原
		}
	}
}

void function2(string a, int p2, int p3)
{
	cout << a[0];
	for (int i = 1; i < a.size(); ++i)
	{
		if (a[i] != '-')	
			cout << a[i];
		else
		{
			if ( ((a[i+1] - a[i-1]) > 1) && ((isalpha(a[i+1]) && isalpha(a[i-1])) || (isdigit(a[i+1]) && isdigit(a[i-1]) )))
			{
				if (p3 == 1)
				{
					for (char j = a[i-1]+1; j < a[i+1]; ++j)//同上，但方向从后到前反序输出
					{
						for (int k = 0; k < p2; ++k)
						{
							cout << (char)toupper(j);//转换小写为大写
						}
					}
				}

				if (p3 == 2)
				{
					for (char j = a[i+1]-1; j > a[i-1]; --j)
					{
						for (int k = 0; k < p2; ++k)
						{
							cout << (char)toupper(j);
						}
					}
				}
			}
			else if(a[i+1] - a[i-1] != 1)
				cout << '-';
		}
	}
}

void function3(string a, int p2, int p3)
{
	cout << a[0];
	for (int i = 1; i < a.size(); ++i)
	{
		if (a[i] != '-')	
			cout << a[i];
		else
		{
			if ( ((a[i+1] - a[i-1]) > 1) && ((isalpha(a[i+1]) && isalpha(a[i-1])) || (isdigit(a[i+1]) && isdigit(a[i-1]) )))
			{
				for (char j = a[i-1]+1; j < a[i+1]; ++j)
				{
					for (int k = 0; k < p2; ++k)
					{
						cout << '*';//填充“*”
					}
				}
			}
			else if(a[i+1] - a[i-1] != 1)
				cout << '-';
		}
	}
}
