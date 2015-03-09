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
	void show_time();
};

void Time::show_time()
{
	cout << "time is " << hour << ":" << min << ":" << sec << endl;
}

int main(int argc, char const *argv[])
{
	Time *p = new Time(12, 23, 34);//使用一个指针指向未命名的对象时直接在类名后写上构造函数的值
	cout << "using p->show_time:" << endl;
	p->show_time();
	delete p;//释放内存
	return 0;
}
