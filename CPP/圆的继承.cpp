#include <iostream>
using namespace std;

const double PI = 3.14;

class Circle
{
public:
	Circle():radius(0){}
	~Circle(){}
	Circle(double r):radius(r){}
	double Area();
	void Display_info();
private:
	double 	radius;
};

double Circle::Area()
{
	return PI * radius * radius;
}

void Circle::Display_info()
{
	cout << "radius = " << radius << endl;
	cout << "Area = " << Area() << endl;
}

class Cylinder: public Circle
{
public:
	Cylinder();
	~Cylinder(){};
	Cylinder(int, int);
	double Volume();
	void Display_info();
private:
	double height;
};

Cylinder::Cylinder():Circle(0), height(0){}

Cylinder::Cylinder(int r, int h):Circle(r), height(h){}

double Cylinder::Volume()
{
	return height * Area();
}

void Cylinder::Display_info()
{
	Circle::Display_info();
	cout << "height = " << height << endl;
	cout << "Volume = " << Volume() << endl;
}

int main(int argc, char const *argv[])
{
	int r, h;
	
	cout << "-->Pleas input a radius: ";
	cin >> r;
	cout << "\nThis is Circle" << endl;
	Circle c(r);
	c.Display_info();

	cout << "\n-->Please input a height: ";
	cin >> h;
	cout << "\nThis is a Cylinder" << endl;
	Cylinder cl(r, h);
	cl.Display_info();

	return 0;
}
