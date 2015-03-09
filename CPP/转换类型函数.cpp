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
	operator double()//ת�����ͺ�������ָ������ֵ���ͣ���ֻ����Ϊ���еĳ�Ա������������Ϊ��Ԫ��������������Ԫ����
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

	c2 = c3 + c1;//�Ӻ����˵����Ͳ�ͬ��������ϵͳ����ͬʱ��û�жԡ�+������������ǣ��ͻ�ȥ����Ƿ�������ת������
	cout << "��Complex�������:" << endl;
	c2.display();
	cout << "��double���������" << endl;
	cout << c2 << endl;
	return 0;
}
