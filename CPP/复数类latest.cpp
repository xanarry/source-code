#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double a = 0, double b = 0): Real(a), Imag(b){}
	~Complex(){}
	friend ostream & operator<<(ostream &os, const Complex t)
	{
		os << "(" << t.Real << "," << t.Imag << "!)";
		return os;
	}

	friend istream & operator>>(istream &is, Complex &t)
	{
		is >> t.Real >> t.Imag;
		return is;
	}

	friend Complex operator+(Complex a, Complex b)
	{
		/****************************
		Complex tmp;
		tmp.Real = a.Real + b.Real;
		tmp.Real = a.Imag + a.Imag;
		return tmp;
		*****************************/
		return Complex(a.Real + b.Real, a.Imag + b.Imag);
	}

	friend Complex operator-(Complex a, Complex b)
	{
		/****************************
		Complex tmp;
		tmp.Real = a.Real - b.Real;
		tmp.Real = a.Imag - a.Imag;
		return tmp;
		*****************************/
		return Complex(a.Real - b.Real, a.Imag - b.Imag);
	}

	Complex operator=(Complex a)
	{
		return Complex(Real = a.Real, Imag = a.Imag);
	}
private:
	double Real, Imag;
};

int main(int argc, char const *argv[])
{
	Complex a, b, c;
	cin >> a >> b;
	c = a;
	cout << "a = " << a << " " << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "a + b = " << a + b << endl;
	cout << "a + 23.32 = " << a + 23.32 << endl;
	cout << "200 + b = " << 200 + b << endl;
	cout << "a - b = " << a - b << endl;
	return 0;
}
