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
	operator double()//转换类型函数不能指定返回值类型，且只能作为类中的成员函数，不能作为友元函数，或者是友元函数
	{
		return real;
	}
	void display()
	{
		cout << "(" << real << "," << imag << ")" << endl;
	}
};

int main(int argc, char const *argv[])
{
	double a = 12, b;
	Complex c1(1, 2.1), c2, c3(3, 7);

	c2 = c3 + c1;//加号两端的类型不同，当编译系统发现同时又没有对“+”运算符重载是，就会去检查是否有类型转换函数
	cout << "以Complex类型输出:" << endl;
	c2.display();
	cout << "以double类型输出：" << endl;
	cout << c2 << endl;
	return 0;
}
