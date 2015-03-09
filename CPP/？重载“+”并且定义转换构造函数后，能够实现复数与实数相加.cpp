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
	friend Complex operator + (Complex a, Complex b);//������&���ֻ��������������������ӣ����Ӿ���ʵ�ָ���������ʵ�����????????
	void display();
};

Complex operator + (Complex a, Complex b)//
{
//	a.real += 10000;//��&��û�м�&���ܶ����ݽ����޸�
	return Complex(a.real + b.real, a.imag + b.imag);
}

void Complex::display()
{
	cout << "(" << real << "," << imag << ")" << endl;
}

int main(int argc, char const *argv[])
{
	Complex t, t1(1, 2.1), t2(3, 3.2);
	cout << "�����������" << endl;
	t = t1 + t2;//+�����˵��������Ͳ�ͬ��ϵͳ�ڽ����������ʱ��ͨ��ת�����캯����������ת��
	t.display();
	cout << "����������ʵ�����" << endl;
	t = t1 + 1000;
	t.display();
	return 0;
}
