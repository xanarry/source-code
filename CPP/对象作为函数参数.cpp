#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	int a;
	int b;
	int c;
	Time(int h, int m, int s):hour(h), min(m), sec(s){}
	void show_time()
	{
		cout << hour << ":" << min << ":" << sec << endl;
	}
	void show_values()
	{
		cout << "a = " << a <<endl << "b = " << b << endl << "c = " << c << endl;
	}
};

void test_fun(Time t)
{
	cout << "this is in test_fun function:" << endl;
	t.show_time();
	t.show_values();
	cout << "now change the value of a,b,c" << endl;
	t.a += 1;
	t.b += 1;
	t.c += 1;
	t.show_values();
}

void test_fun1(Time *p)
{
	cout << endl << "this function is using pointer as paragrem:" << endl;
	cout << "original information" << endl;
	p->show_time();
	p->show_values();
	cout << "now values changed" << endl;
	(p->a) *= 2;
	(p->b) *= 2;
	(p->c) *= 2;
	p->show_time();
	p->show_values();
}

int main(int argc, char const *argv[])
{
	Time t1(12,23,34);
	t1.a = 10;
	t1.b = 11;
	t1.c = 12;
	t1.show_time();
	t1.show_values();

	cout << "now using function :" << endl;
	test_fun(t1);//不是通过指针的传递则无法通过函数去修改远对象中的值
	cout << "after use function to add 1 :" << endl;
	t1.show_values();

	test_fun1(&t1);
	cout << "after use function include pointer * 2 :" << endl;
	t1.show_values();
	cout << "as you can see, the values has changed" << endl;
	return 0;
}
