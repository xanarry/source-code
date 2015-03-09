#include <iostream>
#include <string>
using namespace std;

const float PI = 3.1415926;

class Shape//定义抽象类，凡是含有纯虚函数的类都是抽象类，因为不能直接实例化为对象
{
public:
	virtual float area() const
	{
		return 0.0;
	}
	virtual float volume() const
	{
		return 0.0;
	}
	virtual void ShapeName() const = 0;
};

class Piont: public Shape
{
protected:
	float x;
	float y;
public:
	Piont(float a = 0, float b = 0):x(a), y(b){}
	~Piont(){};
	virtual void ShapeName() const
	{
		cout << "Piont" << endl;
	}
	friend ostream & operator << (ostream &, Piont);
};

ostream & operator << (ostream & output, Piont a)
{
	output << "x = " << a.x <<"\n" << "y = " << a.y << endl;
}

class Circle: public Piont
{
protected:
	float radius;
public:
	Circle(float a = 0, float b = 0, float c = 0):Piont(a, b), radius(c){}
	~Circle(){};
	float area()
	{
		return PI * radius * radius;
	}
	virtual void ShapeName() const
	{
		cout << "Circle" << endl;
	}
	friend ostream & operator << (ostream &, Circle);
};

ostream & operator << (ostream &output, Circle a)
{
	output << "x = " << a.x << "\ny = " << a.y << "\nradius = " << a.radius << "\narea = " << a.area() << endl;
	return output;
}

class Cylinder: public Circle
{
protected:
	float height;
public:
	Cylinder(float a = 0, float b = 0, float c = 0, float d = 0):Circle(a, b, c)
	{
		height = d;
	}
	~Cylinder(){}
	virtual void ShapeName() const
	{
		cout << "Cylinder" << endl;
	}
	float area()
	{
		return PI * radius * radius;
	}
	float volume()
	{
		return area() * height;
	}
	friend ostream & operator << (ostream &, Cylinder);
};

ostream & operator << (ostream &output, Cylinder a)
{
	output << "x = " << a.x << "\ny = " << a.y << "\nradius = " << a.radius << "\nheight = " << a.height << "\narea = " << a.area() << "\nvolume = " << a.volume() << endl;
}

int main(int argc, char const *argv[])
{
	Shape *spe;//抽象类指针

	Piont p(12, 23);
	spe = &p;
	spe->ShapeName();
	cout << p;
	cout << "-----------------" << endl;

	Circle c(1, 1, 3);
	spe = &c;
	spe->ShapeName();
	cout << c;
	cout << "-----------------" << endl;

	Cylinder cy(2, 2, 4, 8);
	spe = &cy;
	spe->ShapeName();
	cout << cy;
	cout << "-----------------" << endl;

	return 0;
}
