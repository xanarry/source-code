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
	Time(int h = 0, int m = 0, int s = 0):hour(h), min(m), sec(s){}
	void show_time();
};

void Time::show_time()
{
	cout << "The time you've input just now is : ";
	cout << hour << ":" << min << ":" << sec << endl;
}

int main(int argc, char const *argv[])
{ 
	cout << "Please input a time: ";
	int h,m,s;
	cin >> h >> m >> s;//输入数字到变量用于存储临时数据用来给创建对象时的构造函数传递参数
	Time _time(h,m,s);
	cout << "\ngeneral method:\n";
	_time.show_time();
	cout << endl;

	Time *pto;//创建对象指针
	pto = &_time;//地址指向
	cout << "use \"(*pto).show_time\" output data\n";
	(*pto).show_time();//调用函数way1,使用此方法应该使用括号将*pto括起来，不然则会取函数show_time()的地址，但是没有pto对象，会报错
	cout << "\nuse \"pto->show_time\" output data\n";
	pto->show_time();//调用函数way2
	cout << endl;

	Time t;
	t.test = 1000;
	cout << "using default argument:\n";
	t.show_time();
	cout << endl;
	int *p;//定义指向对象中的变量的指针与正常的指针定义一样
	cout << "this is a pointer to a var in object Time\n";
	p = &t.test;//取地址
	cout << "test data is " << *p << endl;

	//使用指向对象中的函数的的指针输出
	void (Time:: *ptw)();//定义指向对象函数的指针
	ptw = &Time::show_time;//让定义的指针指向对象中的这个函数
	(t.*ptw)();//调用对象t中这个函数
	return 0;
}
