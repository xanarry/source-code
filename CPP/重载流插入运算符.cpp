#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex()//定义构造函数设定默认值
	{
		real = 0;
		imag = 0;
	}
	Complex(double r, double i):real(r), imag(i){}//构造函数
	Complex operator + (Complex &agm);//实现复习相加的函数
	friend ostream & operator << (ostream &, Complex &tmp);
	//重载流插入函数为友元函数，输出必须加ostream,输入必须加istream,固定形式
};

Complex Complex::operator + (Complex &agm)
{
	return Complex(real + agm.real, imag + agm.imag);//返回复数相加结果
}

ostream & operator << (ostream &, Complex &tmp)
{
	cout << "(" << tmp.real << "," << tmp.imag << "i)" << endl;//实现"<<"符号的重载
}

int main(int argc, char const *argv[])
{
	Complex t1(1,3), t2(2,5), t3;
	cout << t1;
	cout << t2;
	t3 = t1 + t2;
	cout << t3;
	return 0;
}
