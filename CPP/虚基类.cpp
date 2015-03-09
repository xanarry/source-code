#include <iostream>
#include <string>

using namespace std;
const double PI = 3.14;

//Point is a Virtual base class
class Point
{
public:
	virtual double area() const
	{
		return 0.0;
	} 
	virtual double volume() const
	{
		return 0.0;
	} 
	virtual void itsname() const = 0;
};

class Circle: public Point
{
public:
	Circle(double x = 0):r(x){}
	Circle():r(0){}
	~Circle(){}
	virtual double area() const
	{
		return PI * r * r;
	}
	virtual void itsname() const
	{
		cout << "its a Circle" << endl;
	}
private:
	double r;
};

class Cylinder: public Circle
{
public:
	Cylinder(double r, double x = 0):Circle(r), h(x){};
	Cylinder():Circle(0), h(0){};
	~Cylinder(){}
	virtual double volume() const
	{
		return Circle::area() * h;
	}
private:
	double h;
};

int main(int argc, char const *argv[])
{
//	Point p; //we can not use a virtual base class to declare a object
	Circle c(2);
	c.itsname();
	cout << "area is" << c.area() << endl;

	Cylinder cy(2, 5);
	cy.itsname();
	cout << "volume is " << cy.volume() << endl;
	return 0;
}
