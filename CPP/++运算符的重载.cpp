#include <iostream>
#include <windows.h>
using namespace std;

class Time
{
private:
	int min;
	int sec;
public:
	Time()
	{
		min = 0;
		sec = 0;
	}
	Time(int m, int s):min(m), sec(s){}
	Time operator ++ ();//++分为前置自增运算和后置自增运算，()内为空为前置自增运算的重载
	Time operator ++ (int);//()内为加上"int"为前置自增运算的重载
	void display()
	{
		cout << min << ":" << sec << endl;
	}
};

Time Time::operator ++ ()//定义前置自增运算符的重载函数
{
	if(++sec >= 60)
	{
		sec -= 60;
		++min;
	}
	return *this;
}

Time Time::operator ++ (int)//定义后置自增运算符的重载函数
{
//	Time tmp;//(*this);/////?????????
	sec++;
	if(sec >= 60)
	{
		sec -= 60;
		++min;
	}
	return *this;//tmp;//?????????????
}


int main(int argc, char const *argv[])
{
	Time time1(34, 0);
	for(int i = 0; i <= 60; i++)
	{
		time1++;
		time1.display();

		++time1;
		time1.display();
	}
	return 0;
}
