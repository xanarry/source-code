#include <iostream>
using namespace std;

class Time
{
public:
	int hour;
	int min;
	int sec;
	Time(int h, int m, int s):hour(h), min(m), sec(s){}
	void show_time();
};

void Time::show_time()
{
	cout << "time is:" << hour << ":" << min << ":" << sec << endl;
}

void fun(Time &t)//没有指定为cons
{
	t.hour += 1;//引用对象中能够修改成员的值
}

void fun1(const Time &t)
{
//	t.hour += 1;//因为加了const，在对成员值进行修改的时候会报错
	cout << "output the member of object" << endl;
	cout << t.hour << endl;
	cout << t.min << endl;
	cout << t.sec << endl;//可见只能访问其中的值
	cout << "now using function" << endl;
//	t.show_time();//访问的函数应该加有const关键字
}

int main(int argc, char const *argv[])
{
	Time t1(9,23,34);
	fun(t1);//对象的引用相当于函数的指针接口
	t1.show_time();
	fun1(t1);
	return 0;
}
