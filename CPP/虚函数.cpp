/*
describe:
	设计一个图形类（Shape），由它派生出5个派生类:三角形类（Triangle）、
	正方形类（Square）、圆形类（Circle）、矩形类（Rectangle）、梯形类
	（triangle）类，利用虚函数计算图形面积，用一个函数printArea分别输
	出以上5者的面积
date:
	2014/6/8/ 22:40
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.14159;

class Shape
{
public:
	Shape(){}
	~Shape(){}
	virtual double Area(){}
	virtual void PrintArea(){}
};

class Triangle: public Shape
{
public:
	Triangle(double x, double y, double z):a(x), b(y), c(z){}
	~Triangle(){}
	double Area()
	{
		double p = (a + b + c)/2;
		double t = p * (p - a) * (p - b) * (p - c);
		return sqrt(t);
	}
	void PrintArea()
	{
		cout << "Triangle's area  is: " << Area() << endl;
	}
private:
	double a, b, c;
};

class Square: public Shape
{
public:
	Square(double x): a(x){}
	~Square(){}
	virtual double Area()
	{
		return a * a;
	}
	virtual void PrintArea()
	{
		cout << "Square's  area   is: " << Area() << endl;
	}
private:
	double a;
};

class Circle: public Shape
{
public:
	Circle(double x): r(x){}
	~Circle(){}
	virtual double Area()
	{
		return PI * r * r;
	}
	virtual void PrintArea()
	{
		cout << "Circle's  area   is: " << Area() << endl;
	}
private:
	double r;	
};

class Rectangle: public Shape
{
public:
	Rectangle(double x, double y): a(x), b(y){}
	~Rectangle(){}
	virtual double Area()
	{
		return a * b;
	}
	virtual void PrintArea()
	{
		cout << "Rectangle's area is: " << Area() << endl;
	}
private:
	double a, b;
};

class Trapezoid: public Shape
{
public:
	Trapezoid(double us, double ds, double ht): UpSide(us), DownSide(ds), Height(ht){}
	~Trapezoid(){}
	virtual double Area()
	{
		return (UpSide + DownSide) * Height / 2;
	}
	virtual void PrintArea()
	{
		cout << "Trapezoid's area is: " << Area() << endl;
	}
private:
	double UpSide, DownSide, Height;
};



int main(int argc, char const *argv[])
{
	Shape *pointer;

	Triangle tr(3, 4, 5);
	pointer = &tr;
	pointer->PrintArea();

	Square sq(4);
	pointer = &sq;
	pointer->PrintArea();

	Circle ci(4);
	pointer = &ci;
	pointer->PrintArea();

	Rectangle re(2, 4);
	pointer = &re;
	pointer->PrintArea();

	Trapezoid tra(2, 3, 4);
	pointer = &tra;
	pointer->PrintArea();
	return 0;
}
