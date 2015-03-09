//构造函数的名字必须与类名相同，且在建立对象时自动执行
#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int sec;
public:
	Time();
	void set_time();
	void show_time();
};

Time::Time()
{
	hour = 0;
	minute = 0;
	sec = 0;
}

void Time::set_time()
{
	cin >> hour >> minute >> sec;
}

void Time::show_time()
{
	cout << hour <<":" << minute << ":" << sec << endl;
}

int main(int argc, char const *argv[])
{
	Time t1;
	t1.set_time();
	t1.show_time();

	Time t2;
	t2.show_time();
	return 0;
}