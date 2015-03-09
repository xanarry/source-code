#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	int test;
	Time(int h = 0, int m = 0, int s = 0):hour(h), min(m), sec(s){}
	void show_time();
};

void Time::show_time()
{
	cout << "The time you've input just now is : ";
	cout << hour << ":" << min << ":" << sec << endl;
}

int main(int argc, char const *argv[])
{ 
	
	return 0;
}
