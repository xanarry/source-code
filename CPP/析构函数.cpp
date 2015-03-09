#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(int h = 0, int m = 0, int s = 0):hour(h), min(m), sec(s){}
	void shwo_time();
	~Time();
};

void Time::shwo_time()
{
	cout << hour << ";" << min << ":" << sec << endl;
}

Time::~Time()
{
	cout << "this function has excutive";
}

int main(int argc, char const *argv[])
{
	Time t1(12,23,45);
	t1.shwo_time();
	return 0;
}