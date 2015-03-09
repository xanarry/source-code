#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex()//设定默认的构造函数
	{
		real = 0;
		imag = 0;
	}
	Complex(double r)//设定只有一个实数的构造函数
	{
		real = r;
		imag = 0;
	}
	Complex(double a, double b):real(a), imag(b){}//普通构造函数
	friend istream & operator >> (istream &agm, Complex &tmp);//声明重载">>"的函数
	friend ostream & operator << (ostream &, Complex &tmp);//声明重载"<<"的函数
	friend Complex operator + (Complex &a, Complex &b);//声明重载"+"的函数
};

istream & operator >> (istream &agm, Complex &tmp)
{
	cout << "input a Complex num:";//显示提示信息
	cin >> tmp.real >> tmp.imag;//函数主体，即将复数分为两个部分分别输入
}

ostream & operator << (ostream &, Complex &tmp)//引用tmp参数
{
	cout << "(" << tmp.real << "," << tmp.imag << "i)" << endl;//分别输出复数的每个部分
}

Complex operator + (Complex &a, Complex &b)//引用两个对象
{
	return Complex(a.real + b.real, a.imag + b.imag);//重载+函数主体
}

int main(int argc, char const *argv[])
{
	Complex t1(1), t3, t4;
	Complex t2(2, 2.1), a1, a2;
	cin >> a1 >> a2 ;
	cout << "a1 = " << a1;
	cout << "a2 = " << a2;
	t3 = a1 + a2;
	cout << "a1 + a2 = " << t3 << endl;

	cout << "t1 = " << t1;
	cout << "t2 = " << t2;
	t4 = t1 + t2;
	cout << "t1 + t2 = " << t4 << endl;
	return 0;
}
