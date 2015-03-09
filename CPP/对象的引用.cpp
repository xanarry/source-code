#include <iostream>
using namespace std;

class Time
{
private:
	int h;
	int min;
	int s;

public:
	void _set()
	{
		cout << "please input a time:";
		cin >> h >> min >> s;
	}

	void _get()
	{
		cout << h << ":" << min << ":" << s << endl;
	}
};

int main(int argc, char const *argv[])
{
	Time t;
	Time &t1 = t;
	t._set();
	t._get();
	t1._get();
	return 0;
}
