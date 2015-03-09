#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time();
	Time(int h, int m, int s):hour(h), min(m), sec(s)
	{

	}
	void show_time();
};

void Time::show_time()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

Time::Time()
{
	hour = 10;
	min = 10;
	sec = 10;
}

int main(int argc, char const *argv[])
{
	Time t;
	//use no argument Time function
	cout << "use argument Time function:";
	t.show_time();

	//use argument Time function
	cout << "use argument Time function:";
	Time t1(12,10,45);
	t1.show_time();
	return 0;
}