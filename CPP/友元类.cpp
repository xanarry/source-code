#include <iostream>
using namespace std;

class Date;//因为在Time中要用Date类，但是还没有定义，所以先声明

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(int h, int m, int s):hour(h), min(m), sec(s){}
	void display_time(Date t);
};

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d):year(y), month(m), day(d){}
	friend class Time;//定义友元类，必须要见class关键词 
};

void Time::display_time(Date t)//传递date类的对象t,并且使用其参数
{
	cout << "Date: " << t.year << "-" << t.month << "-" << t.day << endl;
	cout << "Time: " << hour << ":" << min << ":" << sec << endl;

	t.year += 5;//对Date类中的私有成员数据进行修改
	puts("");
	cout << "Date: " << t.year << "-" << t.month << "-" << t.day << endl;
	cout << "Time: " << hour << ":" << min << ":" << sec << endl;
}

int main(int argc, char const *argv[])
{
	Time t1(12, 23, 34);
	Date d1(2013, 12, 16);
	t1.display_time(d1);//将对象d1传递给Time中的display函数
	return 0;
}
