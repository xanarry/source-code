#include <iostream>
#include <cstring>

using namespace std;

void mutiply(char *, char *);//声明函数
int main(int argc, char const *argv[])
{
	char a[100];
	char b[100];
	cout << "input factor1: ";
	cin >> a;//以两个字符串形式输入大整数
	cout << "input factor2: ";
	cin >> b;
	mutiply(a, b);//调用函数计算乘法运算
	return 0;
}

void mutiply(char *a, char *b)
{
	const int len = 1000;//设定数字的最大长度为1000位
	int fac1[len + 5];//
	int fac2[len + 5];//
	int result[len + 5];//以上都加五防止计算时下标越界

	//任何数乘以0都等于0
	if ((strlen(a) == 1 && a[0] == '0') || (strlen(b) == 1 && b[0] == '0'))
	{
		cout << 0 << endl;
		return;
	}

	for (int i = 0; i < len + 5; i++)//将表示结果的数组所有位数置为0
	{
		result[i] = fac1[i] = fac2[i] = 0;
	}

	int t = len;
	for (int i = strlen(a); i >= 0; i--)//将乘数2所有位数置为0
	{
		fac1[t--] = a[i] - '0';
	}
	
	t = len;
	for (int i = strlen(b); i >= 0; i--)//将乘数2所有位数置为0
	{
		fac2[t--] = b[i] - '0';
	}

	int location = len;//使用location实现错位相加
	for (int i = len - 1; i >= len - strlen(a); i--)//从末尾向前遍历乘数1
	{
		int index = location;//执行新一次循序运算时获取新的数字存放位置(用于实现错位相加)
		for (int j = len - 1; j >= len - strlen(b); j--)//从末尾向前遍历乘数2
		{
			--index;//数字下标前移
			int temp = fac1[i] * fac2[j] + result[index];//两数相乘并加上之前两个数字相乘的进位
			if (temp >= 10)//如果比10大
			{
				result[index] = temp%10;//取尾数
				result[index - 1] += temp/10;//向前进位
			}
			else
				result[index] = temp;//小于10直接赋值
		}
		location--;//位置自减，实现错位
	}

	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (result[i] != 0)
		{
			flag = i;//获取有效结果的开始下标
			break;
		}
	}
	cout << a << "*" << b << "=";
	for (int i = flag; i < len; i++)//输出结果
	{
		cout << result[i];
	}
	cout << endl;
}