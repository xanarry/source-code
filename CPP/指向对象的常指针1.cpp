#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	int test;
	Time(int h, int m, int s):hour(h), min(m),sec(s){}
	void show_time();
};

void Time::show_time()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

void fun(const Time *t)
{
	cout << "fun_test = " << t->test << endl;
//	t->show_time();//同理，不能使用非const类型的函数
}

int main(int argc, char const *argv[])
{
	Time t1(12,23,34);
	t1.test = 1000;
	const Time *p = &t1;
	t1.show_time();
	cout << "test number = " << p->test << endl;//可以使用指针引用其中的成员
//	p->test = 100;//不能企图通过指向常对象的指针去修改成员
//	p->show_time();//如果要通过指向常对象的指针调用成员函数，则要给函数加上const限定
	fun(&t1);
	return 0;
}
