#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(int h = 0, int m = 0, int s = 0);//在一个类中定义了全部是默认参数的构造函数后，不能再定义重载构造的函数
	void show_time();
};

int main(int argc, char const *argv[])
{
	Time t;
	cout << "直接创建对象，使用默认参数：";
	t.show_time();

	Time t1(12);
	cout << "直接对象，输入一个参数：";
	t1.show_time();

	Time t2(11,06,58);
	cout << "直接对象，输入3个参数：";
	t2.show_time();
	return 0;
}

void Time::show_time()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

Time::Time(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}
