#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	void _show()
	{
		cout << "time is ";
		cout << hour << ":" << min << ":" << sec << endl;
	}
	void _show1() const // 定义常函数，即在函数名后面加上const关键词
	{
		cout << "time is ";
		cout << hour << ":" << min << ":" << sec << endl;
	}
};

int main(int argc, char const *argv[])
{
	const Time t1(10,11,12); //定义常对象
	t1._show1();//自由对象中同时被声明为常量的方法能别外界访问
//	t1._show();//_show()在类中没有被声明为常方法，所以加上这句无法通过编译
	return 0;
}
