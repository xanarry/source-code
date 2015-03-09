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
	void set_time(Time &);
	void show_time(Time &);
	Time t1;
	set_time(t1);
	show_time(t1);

	Time t2;
	set_time(t2);
	show_time(t2);
	return 0;
}

void set_time(Time &t)
{
	cin >> t.h >> t.min >> t.s;
}

void show_time(Time &t)
{
	cout << t.h << ":" << t.min << ":" << t.s << endl;
}
