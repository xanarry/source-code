#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	void f1();
	try
	{
		f1();
	}
	//if change double to another data type, this program would run error, because the precedure can not find
	//'catch' to capture what 'throw' had throw before!
	catch(double)
	{
		cout << "OK f1" << endl;
	}
	cout << "end main" << endl;
	return 0;
}

void f1()
{
	void f2();
	try
	{
		f2();
	}
	catch(char)
	{
		cout << "OK f2" << endl;
	}
	cout << "end f1" << endl;
}

void f2()
{
	void f3();
	try
	{
		f3();
	}
	catch(int)
	{
		cout << "OK f3" << endl;
	}
	cout << "endl f2" << endl;
}

void f3()
{
	double a = 0;
	try
	{
		throw a;
	}
	catch(float)
	{
		cout << "BIG OK" << endl;
	}
	cout << "end f3" << endl;
}
