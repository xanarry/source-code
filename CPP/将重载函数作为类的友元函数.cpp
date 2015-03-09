#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex(double a = 0, double b = 0):real(a), imag(b){}
	void display();
	friend Complex operator + (Complex a, Complex b);//如果给参数加上&后只能用于两个对象相加，没有加&则
													 //可以直接实现后面两个函数的功能,即实现复数对象与实数相加
	friend Complex operator + (double t, Complex a); //
	friend Complex operator + (Complex a, double t); //
};

void Complex::display()
{
	cout << "(" << real << "," << imag << "i" << ")" << endl;
}

Complex operator + (Complex a, Complex b)
{
	return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator + (Complex a, double t)
{
	return Complex(a.real + t, a.imag);
}

Complex operator + (double t, Complex a)
{
	return Complex(a.real + t, a.imag);
}

int main(int argc, char const *argv[])
{
	Complex t1(1, 2);
	Complex t2(2, 3);
	Complex t3 = t1 + t2;
	cout << "t1 = "; t1.display();
	cout << "t2 = "; t2.display();
	cout << "t2 + t1 = "; t3.display(); 
	return 0;
}
