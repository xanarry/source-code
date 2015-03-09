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
	void Show_Time() const
	{
		cout << hour << ":" << min << ":" << sec << endl; 
	}
};

int main(int argc, char const *argv[])
{
	const Time t1(12,23,34);//指向常对象的指针
	Time const * p1;
	p1 = &t1;
	p1->Show_Time();
	return 0;
}
