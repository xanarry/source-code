#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(int h, int m, int s):hour(h), min(m), sec(s)
	{

	}
	void show_time()
	{
		cout << hour << ":" << min << ":" << sec << endl;
	}
};

int main(int argc, char const *argv[])
{
	Time t1(12,23,59);
	t1.show_time();
	return 0;
}

