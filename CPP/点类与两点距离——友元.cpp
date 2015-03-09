#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
	Point();
	~Point(){};
	Point(double, double);
	friend double Distance(Point a, Point b);
	void display();
private:
	double x;
	double y;
};

Point::Point(double a, double b)
{
	x = a;
	y = b;
}

void Point::display()
{
	cout << "(" << x << "," << y << ")" << endl;
}

double Distance(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(int argc, char const *argv[])
{
	Point a(0, 0);
	Point b(1, 1);
	double distance = Distance(a, b);
	cout << "distance = " << distance << endl;
	return 0;
}
