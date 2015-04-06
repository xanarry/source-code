#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct BigInteger
{
	static const int max_len = 1000;//数字的最大长度
	int num[max_len];//保存数字的每位数到数组，数字时逆序的，1234保存格式为4321
	int len;//数字的有效长度

	BigInteger(long long n)//构造函数，接收整数形式输入
	{
		len = 1;
		memset(num, 0, sizeof(num));
		if (n > 0)
		{
			int i = 0;
			while (n > 0)
			{
				num[i++] = n % 10;
				n /= 10;
			}
			len = i;
		}
	}

	BigInteger(string n)//构造函数接收字符串形式输入
	{
		memset(num, 0, sizeof(num));
		for (int i = n.length() - 1, t = 0; i >=0; i--)
			num[t++] = (int)(n[i] - '0');
		len = n.length();
	}

	BigInteger()//默认构造函数，初始值为0
	{
		len = 1;
		memset(num, 0, sizeof(num));
	}
	~BigInteger(){}

	void clean()//清理掉数字前面的0，将“001509”，计算时表示为“905100”，将后面的0清除，整理为9051，最终输出1509
	{
		while (len > 1 && !num[len - 1])
			len--;
	}

	friend BigInteger operator+ (BigInteger a, BigInteger b)//加法，逆序
	{
		a.len = a.len > b.len ? a.len + 1 : a.len + 1;//考虑进位情况，循环两个数中最大的位数加1次
		for (int i = 0; i < a.len; i++)//从个位开始
		{
			int temp = a.num[i] + b.num[i];//两个数的各位数相加
			a.num[i] = temp % 10;//求余保存到数a
			if (temp >= 10)//实现进位
				a.num[i + 1] += temp /= 10;
		}
		a.clean();//整理
		return a;
	}

	friend BigInteger operator- (BigInteger a, BigInteger b)//减法,逆序
	{
		if (a > b)//a>b才做减法
		{
			for (int i = 0; i < a.len; i++)
			{
				if (a.num[i] < b.num[i])//不够减
				{
					a.num[i] = a.num[i] + 10 - b.num[i];//如果被减数不是零则加10后在相减
					b.num[i + 1]++;//减数的下一位加1，因为向被减数的下一位，等同于在减数的下一位上加1
				}
				else//如果够减则两个数直接相减
					a.num[i] -= b.num[i];
			}
		}
		else//否则返回0
			memset(a.num, 0, sizeof(a.num));
		a.clean();
		return a;
	}

	friend BigInteger operator* (BigInteger a, BigInteger b)//乘法，逆序
	{
		BigInteger result;//应为a,b两个数中的每个数要重复操作，所有开新的变量保存结果
		for (int i = 0; i < a.len; i++)//遍历乘数A
		{
			for (int j = 0; j < b.len; j++)//遍历乘数B
			{
				/////////////两个数相乘的结果///加上上次计算的进位值
				int temp = a.num[i] * b.num[j] + result.num[i + j];
				cout << "a[" << i << "] * b[" << j << "] + result[" << i + j << "] = " << temp << endl;
				result.num[i + j] =  temp % 10;//取余数保存
				if (temp >= 10)//进位，错误相加同时进行
					result.num[i + j + 1] += temp / 10;
			}
		}
		result.len = a.len + b.len;//两数相乘的最大乘数是两个乘数的长度之和
		result.clean();
		return result;
	}

	
	friend BigInteger operator/ (BigInteger a, BigInteger b)//除法，顺序
	{
		/*
		 *比如175/6=29...3
		 *第一次循环：temp=1<6 不执行操作，然后temp=1*10=10
		 *第二次循序：因为temp=10+7=17 >= 6, 不断用temp-6，能减2次，保存2，然后temp剩下5， temp=5*10=60
		 *第三次循序：因为temp=50+5=55 >= 6, 不断用temp-6，能减9次，保存9，然后temp剩下2， temp=2*10=20
		 *循环结束，所以结果是29
		 */
		BigInteger result = 0, temp;//定义变量保存结果和辅助计算中间数
		for (int i = a.len - 1; i >= 0; i--) 
		{
			temp.num[0] = a.num[i];//加上下一位数，因为是数组形式，直接赋值到temp.num[0]
			while (temp >= b)//迭代相加
			{
				temp = temp - b;
				result.num[i]++;//保存相减次数
			}
			temp = temp * 10;//扩大十倍
		}
		result.len = a.len + 1;
		result.clean();
		return result;
	}

	friend BigInteger operator% (BigInteger a, BigInteger b)//模运算
	{
		return a - (a / b) * b;
	}

	BigInteger operator= (string n)//重载赋值符号
	{
		for (int i = n.length() - 1, t = 0; i >= 0; i++)
			num[t++] = (int)(n[i] - '0');
		len = n.length();
	}

	friend bool operator < (const BigInteger &a, const BigInteger &b)//定义小于运算符
	{
		if (a.len < b.len)//首先比较长度
			return 1;
		else if (a.len == b.len)//长度相同依次比较每一位数
		{
			for (int i = a.len - 1; i >= 0; i--)
				if (a.num[i] != b.num[i])//不同时才比较
					return a.num[i] < b.num[i];
		}
		else
			return 0;
	}

	friend bool operator > (const BigInteger &a, const BigInteger &b)
	{
		return b < a;
	}

	friend bool operator >= (const BigInteger &a, const BigInteger &b)
	{
		return !(a < b);
	}

	friend bool operator <= (const BigInteger &a, const BigInteger &b)
	{
		return !(b > a);
	}

	friend bool operator == (const BigInteger &a, const BigInteger &b)
	{
		return !(a > b) && !(a < b);
	}

	friend bool operator != (const BigInteger &a, const BigInteger &b)
	{
		return !(b == a);
	}

	friend ostream& operator << (ostream &os, const BigInteger n)
	{
		for (int i = n.len - 1; i >= 0; i--)
			os << n.num[i];
		return os;
	}

	friend istream& operator >> (istream &is, BigInteger &n)
	{
		string s;
		is >> s;
		n = BigInteger(s);
		return is;
	}
};

int main(int argc, char const *argv[])
{
	BigInteger a = BigInteger("23");
	BigInteger b = BigInteger("97");

	cout << a << "+" << b << "=" << (a + b) << endl;
	cout << a << "-" << b << "=" << (a - b) << endl;
	cout << a << "*" << b << "=" << (a * b) << endl;
	cout << a << "/" << b << "=" << (a / b) << endl;
	cout << a << "%" << b << "=" << (a % b)<< endl;

	BigInteger n, m;
	cin >> n >> m;
	cout << n * m << endl;
	return 0;
}