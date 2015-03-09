#include <iostream>
using namespace std;

class Point
{
public:
	 Point(){}
	 /*virtual*/ ~Point()//确定是否定义析构函数为虚函数
	 {
	 	cout << "exit Point destrutor" << endl;
	 }
};

class Circle: public Point
{
public:
	Circle(){}
	~Circle()
	{
		cout << "exit Circle destrutor" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Point *p;//定义指向基类的指针
	p = new Circle;//基类指针指向派生类
	delete p;//如果基类析构函数是虚函数，这执行基类和派生类的析构函数，如果没有，只基类析构函数

	cout << endl;
	Circle *p1 = new Circle;//
	delete p1;
	return 0;
}
