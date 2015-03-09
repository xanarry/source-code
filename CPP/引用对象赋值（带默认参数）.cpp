#include <iostream>
using namespace std;

class Time
{
public:
	int h;
	int min;
	int s;
};

int main(int argc, char const *argv[])
{
	void set_time(Time &, int h = 0, int min = 0, int s = 0);
	void show_time(Time &);
	Time t1;
	set_time(t1, 12, 10 ,56);
	show_time(t1);

	Time t2;
	set_time(t2);
	show_time(t2);
	return 0;
}

void set_time(Time &t, int h = 0, int min = 0, int s = 0)
{
	t.h = h;
	t.min = min;
	t.s = s;
}

void show_time(Time &t)
{
	cout << t.h << ":" << t.min << ":" << t.s << endl;
}
