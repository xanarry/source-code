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
	Complex Add(Complex t);
	void display();
};

Complex Complex::Add(Complex t)
{
	Complex r;
	r.real = real + t.real;
	r.imag = imag + t.imag;
	return r;
}

void Complex::display()
{
	cout << "(" << real << "," << imag << "i" << ")" << endl;
}

int main(int argc, char const *argv[])
{
	Complex a1(3,5), a2(2,7);
	Complex b = a1.Add(a2);
	cout << "a1 = "; a1.display();
	cout << "a2 = "; a2.display();
	cout << "a1+a2 = "; b.display();
	return 0;
}
