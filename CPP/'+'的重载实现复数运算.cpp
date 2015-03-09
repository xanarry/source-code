#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex(double a = 0, double b = 0):real(a), imag(b){}
	Complex operator + (Complex &t);//相当于在类中定义一个（operator+）函数
	void display();
};

void Complex::display()
{
	cout << "(" << real << " , " << imag << "i" << ")" << endl;
}

Complex Complex::operator + (Complex &t)//
{
	Complex c;
	c.real = real + t.real;
	c.imag = imag + t.imag;
	return c;
}

int main(int argc, char const *argv[])
{
	Complex a1(1,3);
	Complex a2(2,2.3);
	Complex c;
	c = a1 + a2;
	cout << "a1 = "; a1.display();
	cout << "a2 = "; a2.display();
	cout << "a1 + a2 = "; c.display();
	return 0;
}
