#include <iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y = 0, int m = 0, int d = 0)
	{
		year = y;
		month = m;
		day = d;
	}
	~Date(){};
	void show_date()
	{
		cout << year << '-' << month << '-' << day;
	}
};

class Time: public Date
{
private:
	int hour;
	int min;
	int sec;
public:
	//可以写成 Time(int y, int mh, int d, int h, int mn, int s):hour(h), min(mn), sec(s),Date(y, mh, d){}
	//在此调用基类的构造函数,不能将其写到新构造函数体中;可以将构造函数写到类外，声明为Time();
	Time(int y, int mh, int d, int h, int mn, int s):Date(y, mh, d)
	{
		hour = h;
		min = mn;
		sec = s;//新类中的构造函数
	}
	~Time(){};
	void show_time()
	{
		show_date();
		cout << ' ' << hour << ":" << min << ":" << sec << endl;
	}
};

/*
Time::Time(int y, int mh, int d, int h, int mn, int s):Date(y, mh, d)//在此调用基类的构造函数,不能将其写到新构造函数体中
{
	hour = h;
	min = mn;
	sec = s;//新类中的构造函数
}*/

int main(int argc, char const *argv[])
{
	Time t1(2014, 4, 25, 21, 11, 15);
	t1.show_date();//基类中的show_date()是公共函数，派生时使用的公共派生，所以此处能使用这个函数
	cout << endl;
	t1.show_time();
	return 0;
}
