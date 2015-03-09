#include <iostream>
using namespace std;

const double PI = 3.1415926;

class Point
{
protected:
	float x, y;
public:
	Point(float x = 0, float y = 0);
	void setPiont(float, float);
	float getX() const
	{
		return x;
	}
	float getY() const
	{
		return y;
	}
	friend ostream & operator << (ostream &, const Point &);
};

Point::Point(float a, float b)
{
	x = a;
	y = b;
}

void Point::setPiont(float a, float b)
{
	x = a;
	y = b;
}

ostream & operator << (ostream &output, const Point &p)
{
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}

/////////////////////////////////////////////////////////////////////
class Circle: public Point
{
protected:
	float radius;
public:
	Circle(float x = 0, float y = 0, float r = 0);
	void setRadius(float);
	float getRadius() const;
	float area() const;
	friend ostream & operator << (ostream &, const Circle &);
};

Circle::Circle(float a, float b, float r):Point(a, b), radius(r){}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getRadius() const
{
	return radius;
}

float Circle::area() const
{
	return PI * radius * radius;
}

ostream & operator << (ostream & output, const Circle &c)
{
	output << "Center = [" << c.x << "," << c.y << "], r = " << c.radius << ", area = " << c.area() << endl;
	return output; 
}

///////////////////////////////////////////////////////////////////
class Cylinder: public Circle
{
protected:
	float height;
public:
	Cylinder(float a = 0, float b = 0, float r = 0, float h = 0);
	void setHeight(float);
	float getHeight() const;
	float area() const;
	float volunme() const;
	friend ostream & operator << (ostream &, const Cylinder &);
};

Cylinder::Cylinder(float a, float b, float r, float h):Circle(a, b, r), height(h){}

void Cylinder::setHeight(float h)
{
	height = h;
}

float Cylinder::getHeight() const
{
	return height;
}

float Cylinder::area() const
{
	return 2 * Circle::area() + 2 * PI * radius * radius;
}

float Cylinder::volunme() const
{
	return height * area();
}

ostream & operator << (ostream & output, const Cylinder & c)
{
	output << "Center = [" << c.x << "," << c.y << "],  r = " << c.radius << "  h = " << c.height << "  area = " << c.area() << "  volunme = " << c.volunme() << endl;
	return output; 
}

int main(int argc, char const *argv[])
{
	cout << "Point-----------------------------------" << endl;
	Point p(1, 23);
	cout << "x = " << p.getX() << endl;
	cout << "y = " << p.getY() << endl;
	cout << "\nCircle----------------------------------" << endl;

	Circle c(1, 1, 3);
	cout << "x = " << c.getX() << endl;
	cout << "y = " << c.getY() << endl;
	cout << "r = " << c.getRadius() << endl;
	cout << c.area();
	cout << "\n\nCircle1---------------------------------" << endl;

	Circle c1;
	c1.setPiont(2, 2);
	c1.setRadius(12);
	cout << "x = " << c1.getX() << endl;
	cout << "y = " << c1.getY() << endl;
	cout << "r = " << c1.getRadius() << endl;
	cout << c1.area();
	cout << c1;
	cout << "\nCylinder--------------------------------" << endl;

	Cylinder cl(1, 2, 3, 4);
	cout << "x = " << cl.getX() << endl;
	cout << "y = " << cl.getY() << endl;
	cout << "r = " << cl.getRadius() << endl;
	cout << "h = " << cl.getHeight() << endl;
	cout << cl;
	return 0;
}
