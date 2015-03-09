#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(int h, int m, int s):hour(h), min(m), sec(s){}
	friend void display(Time &t);//参数是对象的引用
};

void display(Time &t)
{
	cout << "hour = " << t.hour << endl;
	cout << "min = " << t.min << endl;
	cout << "sec = " << t.sec << endl; 
} 

int main(int argc, char const *argv[])
{
	Time t1(12, 23, 34);
	display(t1);
	return 0;
}