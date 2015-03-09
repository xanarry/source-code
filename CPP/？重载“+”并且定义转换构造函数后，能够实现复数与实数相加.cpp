#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(double a, double b):real(a), imag(b){}
	Complex(double r)
	{
		real = r;
		imag = 0;
	}
	friend Complex operator + (Complex a, Complex b);//参数加&后就只能用于两个复数对象相加，不加就能实现复数对象与实数相加????????
	void display();
};

Complex operator + (Complex a, Complex b)//
{
//	a.real += 10000;//加&与没有加&都能对数据进行修改
	return Complex(a.real + b.real, a.imag + b.imag);
}

void Complex::display()
{
	cout << "(" << real << "," << imag << ")" << endl;
}

int main(int argc, char const *argv[])
{
	Complex t, t1(1, 2.1), t2(3, 3.2);
	cout << "复数对象相加" << endl;
	t = t1 + t2;//+号两端的数据类型不同，系统在进行两数向加时会通过转换构造函数进行类型转换
	t.display();
	cout << "复数对象与实数相加" << endl;
	t = t1 + 1000;
	t.display();
	return 0;
}
